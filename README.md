# PUSH_SWAP

L'objectif de PushSwap est de partir d'une stack A donnee en argument, et de la trier dans l'ordre croissant en un minimum de coups.

| Stack Size | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- |  --- | --- | --- |  --- | --- |
| 2 | 1 ||||| >1 |
| 3 | 2 ||||| >2 |
| 5 | 12 ||||| >12 |
| 100 | 700 | 900 | 1100 | 1300 | 1500 | >1500 |
| 500 | 5500 | 7000 | 8500 | 10000 | 11500 | >11500 |

- ⚠️ Et les mouvements de notre stack sont limites!

Beaucoup vous diront: Bouboubou c'est debile, pourquoi on doit le faire avec ces mouvements?   
---> Imaginez-vous que vous controlez un robot, et malheureusement votre robot ne fait pas encore du breakdance
Et bien vous devrez vous limiter a ces capacites.

![robotbreakdance](https://user-images.githubusercontent.com/52299490/146198572-974a1984-b3de-48e3-93b6-57b3ea08877c.jpeg)

| Moves | Explications |
| --- | --- |
| ra  | Place La tete de la stack A ( la premiere valeur ) a la fin de celle-ci |
| rb  | Place la tete de la stack B a la fin de celle-ci |
| rr  | Execute les mouvements ra && rb |
| rra | Place la queue de la stack A ( la derniere valeur ) en tete de celle-ci |
| rrb | Place la queue de la stack B en tete de celle-ci |
| rrr | Execute les mouvements rra && rrb |
| sa  | Echange la premiere et la seconde valeur de la stack A |
| sb  | Echange la premiere et la seconde valeur de la stack B |
| ss  | Execute les mouvements sa && sb |
| pa  | Push la valeur en tete de la stack A en tete de la stack B |
| pb  | Push la valeur en tete de la stack B en tete de la stack A |
| pp  | mmmmh, non celle-ci n'existe pas... |

## 💡 Les outils :
Dans un premier temps, je vous conseille de commencer a creer vos outils afin de vous faciliter le projet.
Pour simuler la stack, je vais utiliser une liste chainee.
⚠️ Vous pouvez tres bien utiliser des tableaux d'entiers, ca sera un peu plus difficile (de mon point de vue) mais bien fait, beaucoup plus efficace qu'une stack!


Restons simpliste: Avec une liste pour mes valeurs stack, et une liste pour mes intructions inst.

```
// ------------------------------------------ //
// ---------------   INST   ----------------- //
struct s_inst
{
	char	*inst;
	t_inst	*next;
};

// -------------------------------------------- //
// ----------------   STACK   ----------------- //
struct s_stack
{
	int		value;
	t_stack	*next;
};
```
Pour votre utilisation de la stack quelques fonctions primaires:
```
t_stack	*ft_stack_create(int value);                        // Creation d'un maillon.
void	ft_stack_addfront(t_stack **data, t_stack *elem);   // Ajout d'un maillon en tete de liste
void	ft_stack_addback(t_stack **data, t_stack *elem);    // Ajout d'un maillon en queue de liste
void	ft_stack_popback(t_stack **data);                   // Efface le dernier maillon
int	ft_stack_size(t_stack *data);                       // Donne la taille de la liste
void	ft_stack_clear(t_stack **data);                     // Efface la liste

t_stack	*ft_stackdup(t_stack *list);                        // Fais une copie d'une stack
```
Et pareil avec notre liste d'instructions avec ses fonctions: 
```
t_inst	*ft_inst_create(char *inst);
void	ft_inst_addback(t_inst **data, t_inst *elem);
void	ft_inst_popback(t_inst *data);
void	ft_inst_clear(t_inst **data);

void	ft_inst_print(int fd, t_inst *data);                // Affichera notre liste
```

💡 Pourquoi nous avons une liste pour les instructions: 
- Pour ne pas appeler write partout dans notre code, ce qui nous fera gagner enormement de temps d'execution.

Pour les mouvements: J'utilise une concatenation de fonctions ce qui rend plus lisible mon code. Vous pouvez faire les votres, moi j'aime bien ce format si on l'utilise avec un enum. ex: `_rx(sa, NULL, A);` pour executer l'instruction RA.

```
enum e_opt
{
	A = 0,
	B,
	R,
};
```

##### Les Mouvements bruts:
```
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_a, t_stack **stack_b);
```
Le mouvement en lui-meme qui va modifier mes stacks. Elle modifie uniquement les pointeurs de mes stacks.
Les swaps de valeur sont a utiliser avec des tableaux. 

##### Les mouvements pilotes:
```
void	_rx(t_inst **inst, t_stack **sa, t_stack **sb, int move);
void	_rrx(t_inst **inst, t_stack **sa, t_stack **sb, int move);
void	_sx(t_inst **inst, t_stack **sa, t_stack **sb, int move);
void	_px(t_inst **inst, t_stack **sa, t_stack **sb, int move);
```
Charges de push l'instruction dans la liste 'inst' et d'appliquer le mouvement a mes stacks. ex:

```void	_rx(t_inst **inst, t_stack **sa, t_stack **sb, int move)
{
	if (move == A)
	{
		ft_rotate(sa);
		ft_inst_addback(inst, ft_inst_create("ra\n"));
	}
	else if (move == B)
	{
		ft_rotate(sb);
		ft_inst_addback(inst, ft_inst_create("rb\n"));
	}
	else if (move == R)
	{
		ft_rotate(sa);
		ft_rotate(sb);
		ft_inst_addback(inst, ft_inst_create("rr\n"));
	}
}
```

Maintenant que nos outils sont fonctionnels (oui, je vous encourage a faire des tests pour savoir s'ils fonctionnent correctement dans tous les cas)
Nous pouvons commencer le project: 

## Le Parsing :

//////
⚠️ Attention ⚠️ Tout ce que je fais dans mon parsing n'est pas demander par l'ecole ( bien que ca soit du bon sens de le faire ) ⚠️
Dans le doute comparer avec l'output du checker Linux/Mac fournis par le suject.

```
 ./push_swap "" 2 3                       \\ Error
 ./push_swap 0 1 - 2                      \\ Error
 ./push_swap 0 1 ----2                    \\ Error
 ./push_swap 42a                          \\ Error
 ./push_swap 0 1 2 0                      \\ Error
 ./push_swap -0000000000000002147483649   \\ Error 

 ./push_swap                        \\ OK
 ./push_swap +2                     \\ OK
 ./push_swap 00000000000000001 2    \\ OK
 ./push_swap "0 1 2" "3 4 5"        \\ OK 
 ./push_swap "0 2 1" "3 4 5"        \\ OK 
```

Les valeurs de notre stack son fournis avec les arguments du main grace a `char **argv`. 
Dans le cadres de ce project, nous n'accepterons uniquement des entier, sans doublons.  
- Pas de Charactere autre que Digit, - et + ( oui on doit pouvoir gerer les negatifs ) 
- Pas de Doublons
- Dois etre conenue entre INT_MIN et INT_MAX ( comprit )
- ⚠️ Si une erreur est trouver: le programme s'arrete, nous renverons `1` et `Error\n` sur STD_ERR : `write(2, msg, strlen(msg))`

##### Etape 1 : Transforming
`int ft_take_arg(t_inst **arg, char **av, int ac)`, transforme nos arguments en une sperbe list `t_inst *`.
Dans le cas ou la len d'un de nos arguments est egal a Zero. c'est que c'est un arguments Vide.

##### Etape 2 : Numbers
Es-ce que tout nos arguments son bien des nombres. 💡 Pas besoin d'utiliser atoi, atol, atoull, etc. il y a plus simple! ( enfin je crois.. ) explication: 
---> Avec un peu de mise en forme rapide, Nous allons pouvoir utiliser strcmp, sur INT_MIN et INT_MAX.

```
# define INT_MAX "2147483647"
# define INT_MIN "2147483648"    // Mais pourquoi il manque le signe moins ???
```

Pour ce faire, je vais decaler un index jusqu'au depart de mon nombre. Skip le sign ( je le prend quand meme en compte ), Les 0.
Ensuite je compte la longeur de mon nombre ( un deuxieme index ). Si elle est egal a 10 ( la len de INT_MAX ) dans ce cas en fonction du sign 
je strcmp soit INT_MIN soit INT_MAX. ⚠️ Si il n'y a qu'un signe et pas de digit derriere, c'est une Erreur.

##### Etape 3 : Doublons

Rien de special, deux pointeurs et on strcmp chaque element entre eux!

![findeparsing](https://user-images.githubusercontent.com/52299490/147415186-3f5b34c1-dec3-4801-9c4c-c3c14bba60a0.jpg)

## Maintenant, Le Coeur du projet:

💡 Donc nous avons differents barem a respecter en fonction du nombre d'arguments mis en entrer. il est donc interessant de faire plusieur algo en fonction du nombre d'arguments.

### Select Sort:
⚠️ Notre stack, fraichement cree peut dors et deja etre ranger! Il faut donc verifier si elle l'est! Sinon :
- `little_sort` < 6     // la Limite est definie par ma capaciter a trier dans une seul stack. 
- `medium_sort` < 11    // 2 fois la limit de little.
- `big_sort`    >= 11	// au dessus de la limite de medium.

## Little Sort:

Pour une petite stack, je vais trier uniquement sur celle-ci ( donc pas de push dans B )
tout simplement, je genere des instructions ( de `i` a `n` ) je duplique ma stack `ft_stackdup()` et j'applique mes intructions
Si ca ne marche pas, je supprime la derniere et j'essaye avec une autre ( de facon recursive ). 

###### C'est comme du brut force ( mais un peu guide ).
- on ne peut pas faire deux SA d'affiller.
- Si on fait RA on ne peut pas faire RRA.
- Si on fait RRA on ne peut pas faire RA.

Si Une instruction ne trie pas, on augmente le nombre d'instruction de 1 et on recommence! 

```
t_inst	*ft_bt_solution(t_stack *stack, int deep, int max_deep)
{
	t_inst	*inst;
	int		depth[2];

	inst = NULL;
	depth[ACT] = 0;
	depth[MAX] = deep;
	if (ft_gen(stack, &inst, "sa\n", depth) == EXIT_SUCCESS)
		return (inst);
	inst = NULL;
	if (ft_gen(stack, &inst, "ra\n", depth) == EXIT_SUCCESS)
		return (inst);
	inst = NULL;
	if (ft_gen(stack, &inst, "rra\n", depth) == EXIT_SUCCESS)
		return (inst);
	inst = NULL;
	if (deep < max_deep)
		inst = ft_bt_solution(stack, deep + 1, max_deep);
	return (inst);
}
```
On s'arrete seulement quand c'est trie!
```
static int	ft_check_possibility(t_stack *stack, t_inst *lst_inst)
{
	t_stack	*stack_cpy;
	int		ret;

	stack_cpy = ft_stackdup(stack);
	while (lst_inst)
	{
		if (!ft_strcmp(lst_inst->inst, "sa\n"))
			ft_swap(&stack_cpy);
		else if (!ft_strcmp(lst_inst->inst, "ra\n"))
			ft_rotate(&stack_cpy);
		else
			ft_reverse_rotate(&stack_cpy);
		lst_inst = lst_inst->next;
	}
	ret = ft_isvalide_stack(stack_cpy, ASC);
	ft_stack_clear(&stack_cpy);
	return (ret);
}
```
###### Si jamais vous avez des questions hesiter a me posser des questions. Faire commeca n'est pas la solution la plus simple, ni la plus optimal mais c'est un bon exercise pour utiliser la recursivite. 💡 Si vous integrer les movements PB PA RB RRB RR RRR, ca peut donner qqchose de vraiment tres preforment pour les intruction, mais ca sera tres gourmand en temps de calcule! 

### Medium Sort:

Pour le medium, c'est simple. 
je calcule la mediane et ce qui est inferieur je le push dans B, J'applique le Little sort sur la stack A
et sur la stack B, Little sort Reverse, Reverse pour pouvoire les push dans le bon ordre dans A.

###### 💡Une tres bonne opti a faire ici serait de Merge les instructions des deux Little sort, ex:  RA && RB = RR.

## Big Sort:

Mon big_sort decoule de l'algorythm Insert Sort, un algo tres modulable qui nous permet d'ajouter plein d'optimisation.
Ici, nous allons remplir une list t_inst avec le retour de chaque etape tel que : `ft_inst_addback(&inst, ft_etapeX(&sa, &sb, etc ));`
qui nous permettra d'afficher nos instruction d'un coup a la fin de notre algo. 

#### 1. Fill Stack B

###### La PLSSC ( Plus longue sous suite croissante ) [ BON, c'est pas ce que j'ai fait mais vous pourrais le faire! ]
une bonne opti a faire ici, c'est trouver la PLSSC, de notre stack originel.
Je me suis contenter de prendre la premier suite croissante a partir de la plus petite valeur de ma stack. 
###### ( peut etre plus tard, hein !? )

Une fois la PLSSC trouver (ou en vrai ce que vous voulais garder dans votre stack), allons chercher la mediane de notre liste.
##### 🔔 Quesqu'une mediane: 
C'est la valeur qui compte autant ( ou une difference de +-1 ) de valeur inferieur et de valeur superieur a celle ci.
Pas besoin de trier et de garder l'index de chaque valeur! Nous allons nous en servir qu'une fois ici.

Une fois fait, nous allons push dans B toute les valeur qui ne ce trouve pas dans PLSSC et Inferieur a notre mediane.
Puis toute les valeur Superieur ( mediane comprit ) Non dans PLSSC. 

Nous devrions nous retrouver avec seulement les valeur de PLSSC Dans A. Et le reste des valeur dans B partitionne en 2.
![Fillstack](https://user-images.githubusercontent.com/52299490/146216548-2c364365-fe06-4f81-aeb9-50b6d7d33d3f.png)

#### 2. Best Push `t_inst  *ft_best_push(t_stack **sa, t_stack **sb, int len_sb)`

Best Push, c'est la fonction mere de l'algo, elle calculera le cout minimum en instruction d'une valeur X pour la push a ca place de la stack B a la stack A.
Puis elle executera ces instruction, avant de nous retourner cette meme liste d'instruction. 

Pour nos calcule nous allons avoir besoin d'un tableau d'entier, 8 entier precisement:

| | | CALCUL | INIT |
| --- | --- | --- | --- |
| RA | nombre de RA | voir ci dessous | 0 |
| RB | nombre de RB | L'index mis en arguments de la fonction | 0 |
| RRB | nombre de RRB | Le resultat de:  `len_sb - RB` | 0 |
| RRA | nombre de RRB | Le resultat de:  `len_sa - RA` | 0 |
| RR | nombre de RR | Egale au plus petit entre RA && RB | 0 |
| RRR | nombre de RRR | Egale au plus petit entre RRA && RRB | 0 |
| METH | la methode utilisee | voir ci dessous | 0 |
| NI | le nombre d'instruction | resultat du calcule de la methode | INT_MAX |

💡 Penser a utiliser un enum pour: RA RB RRA RRB RR RRR METH et NI 

```
enum	e_move
{
	RA = 0,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	MET,
	NI
};
```

Pour avoir notre nombre de RA ca sera resultat de `ft_place_value(t_satck *sa, int value)`.
il nous faudra lui donner la value evaluer dans la stack B ( la valeur situer a l'index donner en arguments de la stack B )
ensuite tres simple: 5 cas et 1 execption 
```
Si ( la stack est vide )
   --> RA = 0;
Si ( value est plus petite que toutes les valeurs de la stack )
   --> on incremante jusqua la plus petite valeur de la stack
Si ( value est plus grande que toutes les valeurs de la stack )
   --> on incremante jusqua la plus grande valeur de la stack
Si ( value est plus grande que la tete de la stack )
   --> on incremante tant que c'est vrai. 
Sinon
   --> EXECPTION: Si jamais la derniere valeur est inferieur alors nous somme deja au bonne endroit! 
   --> on incremante tant que value est inferieur puis tant que value est superieur.
```
le nombre d'incrementation represante notre nombre de RA! 

Pour la methodes il en existe 4 au totale:
Il nous suffit de calculer chaque cas et de retenir le resultat le plus petit dans NI, et d'enregistrer la methode dans METH :
- 0: ( RA + RB - RR )
- 1: ( RRA + RRB - RRR )
- 2: ( RA + RRB )
- 3: ( RB + RRA )

```
	int  nc[8];              // celui si sera un tableau tempon sur la stack
	int  tot[4];             // tableau pour le calcule de notre methode
	
	tot[0] = (nc[RA] - nc[RR]) + (nc[RB] - nc[RR]) + nc[RR];
	tot[1] = (nc[RA] + nc[RRB]);
	tot[2] = (nc[RRA] - nc[RRR]) + (nc[RRB] - nc[RRR]) + nc[RRR];
	tot[3] = (nc[RRA] + nc[RB]);

	nc[MET] = 1 * (tot[1] < tot[0] && tot[1] < tot[2] && tot[1] < tot[3])
		+ 2 * (tot[2] < tot[0] && tot[2] < tot[1] && tot[2] < tot[3])
		+ 3 * (tot[3] < tot[0] && tot[3] < tot[1] && tot[3] < tot[2]) + 0;

	nc[NI] = tot[0] * (nc[MET] == 0) + tot[1] * (nc[MET] == 1) + tot[2] * (nc[MET] == 2) + tot[3] * (nc[MET] == 3);
```
⚠️ Ceci est du branchless, 

Dans notre tableau nous ne garderons uniquement les resultats du meilleur rencontrer. Si jamais NI est inferieur a celui de notre tableau alors l'integraliter des valeurs sont remplacer par le nouveau!
```
void	ft_remplace_counter(int **ct, int *nc)
{
	(*ct)[RA] = (nc[RA] - nc[RR]) * (nc[MET] == 0) + nc[RA] * (nc[MET] != 0);
	(*ct)[RB] = (nc[RB] - nc[RR]) * (nc[MET] == 0) + nc[RB] * (nc[MET] != 0);
	(*ct)[RR] = nc[RR];
	(*ct)[RRA] = (nc[RRA] - nc[RRR]) * (nc[MET] == 2) + nc[RRA] * (nc[MET] != 2);
	(*ct)[RRB] = (nc[RRB] - nc[RRR]) * (nc[MET] == 2) + nc[RRB] * (nc[MET] != 2);
	(*ct)[RRR] = nc[RRR];
	(*ct)[MET] = nc[MET];
	(*ct)[NI] = nc[NI];
}
```

⚠️ Pour ne pas avoir a verifier l'integraliter de la stack B, Il fait dans un premier temps evaluer les valeurs des deux cote de la stack en meme temps, (🔔 car la queue de la stack, n'est qu'a une instruction de ce retrouver en tete ! )
Et d'avoir comme condition d'arret, le nombre d'instruction de notre meilleur value. Quand l'index ( 🔔 qui represente le nombre de RB) sera egale a NI, alors nous sommes sur davoir deja trouver la meilleur valeur a push!
```
	while (i < ct[NI] && i < len_sb)
	{
		ft_search_push(*sa, *sb, i, &ct);
		ft_search_push(*sa, *sb, len_sb - i - 1, &ct);
		i++;
	}
```

Une fois le Best Push trouver, il faudra construire les instructions grace a notre tableau. 
ca sera le job de notre utils : `t_inst *ft_make_inst(int *best, int methode);`
Puis d'applique a nos stack cette meme liste s'instructions. 

On n'oublie pas de free notre tableau d'entier, en on retoune la liste d'instruction!

Best Push sera appeller tant que la stack B n'est pas vide!   
```
	while (sb != NULL)
		ft_inst_addback(&inst, ft_best_push(&sa, &sb, ft_stack_size(sb)));
```

#### Replace Stack

Etant donner que notre stack etait en mouvement il est fort a parier que la valeur minimum ne ce trouve pas en tete de notre stack.
Ici tout simplement il faudra chercher dans quelle sens nous allons placer la valeur MIN en tete de stack. RA || RRA

tout simplement en comptant le nombre de RA, la longueur de la stack, et si RA est inferieur a len_stack / 2. on prendra celui-ci.

#### Print Inst

Maintenant notre stack est bien trier, il ne nous reste plus que l'affichage de nos intruction. 
Donc nous avons un list chainee. l'opti ici sera de strjoin chaque instruction pour appeller le moins de fois possible write ( il est trop gourmand en temps j'aime pas attendre devant mon ecran ). 

- Combient de caractere nous devons imprimer ( pas oublier les '\n' ).
- malloc notre chaines, la remplire avec nos instructions.
- write.

Une fois nos instruction envoyer, on peut tout free! la stack, nos intructions.

![end-project](https://user-images.githubusercontent.com/52299490/147415849-9653fa76-8acc-4403-a16b-3d5c14c7e0c0.jpg)

Push_swap est terminer bien jouer!




















