# PUSH_SWAP

L'objectif de PushSwap est de partir d'une stack A donne en arguments, et de la trier dans l'ordre croissant en un minimum de coup.
- ⚠️ Les mouvement de notre stack son limiter!
#### Les Moves:

| Moves | Explication |
| --- | --- |
| ra  | Place La tete de la stack A ( la premiere valeur ) a la fin de celle-ci |
| rb  | Place la tete de la stack B a la fin de celle-ci |
| rr  | Execute les mouvements ra && rb |
| rra | Place la queue de la stack A ( la derniere valeur ) en tete de celle-ci |
| rrb | Place la queue de la stack B en tete de celle-ci |
| rrr | Execute les mouvements rra && rrb |
| sa  | Echange la premiere et la seconde valeur de la stack A |
| sb  | Echange la premiere et la seconde valeur de la stack B |
| ss  | Execute les mouvement sa && sb |
| pa  | Push la valeur en tete de la stack A en tete de la stack B |
| pb  | Push la valeur en tete de la stack B en tete de la stack A |
| pp  | mmmmh, non celle-ci n'existe pas...

Beaucoup vous dirons: bouboubou c'est debile, pourquoi on doit le faire avec ces mouvements?   
---> Imaginer vous que vous controller un robots, et malheureusement votre robots ne fait pas encore du breakdance
Et bien vous devrais vous limiter a ces capacite.

![robotbreakdance](https://user-images.githubusercontent.com/52299490/146198572-974a1984-b3de-48e3-93b6-57b3ea08877c.jpeg)

## Le Parsing :

Les valeurs de notre stack son fournis avec les arguments du main grace a `char **argv`. 
Dans le cadres de ce project, nous n'accepterons uniquement des entier, sans doublons.  
- Pas de Charactere autre que Digit, - et + ( oui on doit pouvoir gerer les negatifs )
- Pas de Doublons
- Dois etre conenue entre INT_MIN et INT_MAX ( comprit )

Vue que nous avons deja tout sous forme d'un tableau de char, il nous est facile de le parcourir et de faire nos verification sans rien malloc,
💡 Pas besoin d'utiliser atoi, atol, atoull, etc. il y a plus simple! ( enfin je crois.. ) explication: 
---> Avec un peu de mise en forme rapide, Nous allons pouvoir utiliser strcmp, sur INT_MIN et INT_MAX. 

- ⚠️ Si une erreur est trouver: le programme s'arrete, nous renverons `1` et `Error\n` sur STD_ERR : `write(2, msg, strlen(msg))` 

#### STEP 1: Es-ce bien des Nombres ?
Dans un premier temps, `bool ft_isnumber(char *str)` nous indiquera si les char de la string son valide. 
Il ne nous reste plus qu'a regarder si il est dans la range des entier. 
Pour cela, nous allons cree un ptr sur notre str. et skip: le signe, puis tout les 0 rencontrer (-000000000000003 => 3)
Et comparer le reste de la string avec INT_MIN ou INT_MAX en fonction du signe. 
Si le retour de celui-ci est inferieur a 0 alors c'est une Erreur!

#### STEP 2: N'y a t'il pas de doublons ? 
Simplement avec deux index `i` && `j`, nous allons comparer tout les elements entre eux toujours grace a strcmp.

#### STEP 3: Tout est OK, nous allons pouvoir cree notre stack! 

La stack, restons simple:  
``` 
typedef struct s_lst	t_lst;
struct s_lst
{
	int    value;
	t_lst  *next;
};
```
Tout est parfait, nous allons pouvoir commencer le project tranquillement!

## 💡 Les Utils :
Comme nous utiliserons un liste chainee en guise de stack. vous pouvais deja coder les fonctions pour chaqu'un des mouvements possible:
et d'autre fonctions utils pour votre stack. 

Pour les mouvements: ( vous pouvais faire les votres, moi j'aime bien ce format si on l'utiliser avec deux Define: A = 0 B = 1, ex: `_rx(sa, NULL, A);` pour executer l'instruction RA.
```
void	_rx(t_stack **sa, t_stack **sb, int move);
void	_rrx(t_stack **sa, t_stack **sb, int move);
void	_sx(t_stack **sa, t_stack **sb, int move);
void	_px(t_stack **sa, t_stack **sb, int move);
```
Pour votre utilisation de la stack:
```
t_lst	*ft_stack_create(int value);
void	ft_stack_addback(t_stack **data, t_stack *elem);
int     ft_stack_size(t_stack *data);
void	ft_stack_clear(t_stack **data);

t_stack	*ft_stackdup(t_stack *list);
```

Et nous allons utiliser une autre list pour nos instructions: 
```
typedef struct s_inst	t_inst;
struct s_inst
{
	char	*inst;
	t_inst	*next;
};
```
avec ses fonctions: 
```
t_inst	*ft_inst_create(char *inst);
void	ft_inst_addback(t_inst **data, t_inst *elem);
void	ft_inst_popback(t_inst *data);
void	ft_inst_clear(t_inst **data);
void	ft_inst_print(int fd, t_inst *data);
```

💡 Pourquoi nous avons un list pour les instructions: 
- Pour ne pas appeller write partout dans notre code, ce qui nous ferra gagner Enormement de temps d'execution"
- Pour mon little_sort, que j'explique ci dessous!

## L'Execution :
#### Select Sort:
Notre stack, fraichement cree peut dors et deja etre ranger! Il faut donc verifier si elle l'est!
Puis en fonction de la longeur de notre stack nous allons choisir quelle algorythm nous allons appliquer. Ici:
- `little_sort` <= 7     // la Limite est definie par ma capaciter a trier dans une seul stack. 
- `medium_sort` <= 14    // 2 fois la limit de little.
- `big_sort`    > 14	 // au dessus de la limite de medium.

#### Little Sort:

// WORK IN PROGRESSE

#### Medium Sort:

// WORK IN PROGRESSE

#### Big Sort:

Mon big_sort decoule de l'algorythm Insert Sort, un algo tres modulable qui nous permet d'ajouter plein d'optimisation.
Ici, nous allons remplir une list t_inst avec le retour de chaque etape tel que : `ft_inst_addback(&inst, ft_etapeX(&sa, &sb, etc ));`
qui nous permettra d'afficher nos instruction d'un coup a la fin de notre algo. 

- .1. PLSSC ( plus longue sous suite croissante ) 

// WORK IN PROGRESSE

- .2. Fill Stack B

Une fois la PLSSC trouver, allons chercher la mediane de notre liste. 🔔 Quesqu'une mediane: 
C'est la valeur qui compte autant ( ou une difference de +-1 ) de valeur inferieur et de valeur superieur a celle ci.
Pas besoin de trier et de garder l'index de chaque valeur! Nous allons nous en servir qu'une fois ici.

Une fois fait, nous allons push dans B toute les valeur qui ne ce trouve pas dans PLSSC et Inferieur a notre mediane.
Puis toute les valeur Superieur ( mediane comprit ) Non dans PLSSC. 

Nous devrions nous retrouver avec seulement les valeur de PLSSC.

- .3. Best Push

// WORK IN PROGRESSE

- .4. Replace Stack

Etant donner que notre stack etait en mouvement il est fort a parier que la valeur minimum ne ce trouve pas en tete de notre stack.
Ici tout simplement il faudra chercher dans quelle sens nous allons placer la valeur MIN en tete de stack. RA || RRA

tout simplement en comptant le nombre de RA, la longueur de la stack, et si RA est inferieur a len_stack / 2. on prendra celui-ci.

- .5. Print Inst

Maintenant notre stack est bien trier, il ne nous reste plus que l'affichage de nos intruction. 
Donc nous avons un list chainee. l'opti ici sera de strjoin chaque instruction pour appeller le moins de fois possible write ( il est trop gourmand en temps j'aime pas attendre devant mon ecran ). 

Une fois nos instruction envoyer, on peut tout free! la stack, nos intructions. 🦸 SUPER 🦸

























