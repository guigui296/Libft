/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tous les main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbehra <gbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:59:44 by gbehra            #+#    #+#             */
/*   Updated: 2024/11/10 13:26:56 by gbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FONCTION DE BASE

//strdup
int	main(void)
{
	const char *str1 = "Bonjour, monde!";
	char *dup1 = ft_strdup(str1);
	if (dup1)
	{
		printf("Test 1 : Duplication de la chaine \"%s\"\n", str1);
		printf("Chaine dupliquee : \"%s\"\n\n", dup1);
		free(dup1);
	}
	else
	{
		printf("Erreur : Impossible de dupliquer la chaine \"%s\"\n\n", str1);
	}

	const char *str2 = "";
	char *dup2 = ft_strdup(str2);
	if (dup2)
	{
		printf("Test 2 : Duplication de la chaine vide\n");
		printf("Chaine dupliquee : \"%s\"\n\n", dup2);
		free(dup2);
	}
	else
	{
		printf("Erreur : Impossible de dupliquer la chaine vide\n\n");
	}

	const char *str3 = "Une chaine de caracteres tres longue pour tester la duplication de maniere plus robuste.";
	char *dup3 = ft_strdup(str3);
	if (dup3)
	{
		printf("Test 3 : Duplication d'une longue chaine\n");
		printf("Chaine dupliquee : \"%s\"\n\n", dup3);
		free(dup3);
	}
	else
	{
		printf("Erreur : Impossible de dupliquer la chaine longue\n\n");
	}

	return (0);
}

//calloc
int	main(void)
{
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (arr)
	{
		printf("Test 1 : Allocation de 5 entiers\n");
		printf("Valeurs attendues (toutes à 0) : %d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
		free(arr);
	}

	char *str = (char *)ft_calloc(0, sizeof(char));
	if (str)
	{
		printf("Test 2 : Allocation de 0 éléments réussie\n\n");
		free(str);
	}
	str = (char *)ft_calloc(15, sizeof(char));
	if (str)
	{
		printf("Test 3 : Allocation d'une chaîne de 15 caractères\n");
		strcpy(str, "Hello!");
		printf("Chaine allouee et remplie : \"%s\"\n", str);
		free(str);
	}

	return (0);
}

//strlcat
int	main(void)
{
	char dest1[14] = "Hello, ";
	const char *src1 = "world!";
	size_t size1 = 14;

	printf("Test 1 : size = %zu\n", size1);
	printf("Avant ft_strlcat : dest = \"%s\"\n", dest1);
	size_t result1 = ft_strlcat(dest1, src1, size1);
	printf("Après ft_strlcat : dest = \"%s\"\n", dest1);
	printf("Longueur totale : %zu\n", result1);
	
	return (0);
}

//strlcpy
int	main(void)
{
	char	src[]="123456789";
	char	dest[]="";

	printf("%zu", ft_strlcpy(dest, src, ft_strlen(src)));
	
	return(0);
}

//atoi
int	main(void)
{
	char	*str = "   -1234ab567";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
}

//memcpy
int	main(void)
{
	char	src[37] = "Bonjour, ceci est un test de memcpy!";
	char	dest[37] = "";
	size_t	n = 30;

	printf("Avant ft_memcpy:\n");
	printf("src  = \"%s\"\n", src);
	printf("dest = \"%s\"\n\n", dest);

	ft_memcpy(dest, src, n);

	printf("Apres ft_memcpy (les %zu premiers octets copies):\n", n);
	printf("src  = \"%s\"\n", src);
	printf("dest = \"%s\"\n\n", dest);

	return (0);
}

//strnstr
int	main(void)
{
	const char	*str1 = "Bonjour nous sommes a 42";
	const char	*str2 = "nous";
	size_t		len =  '\0';

	printf("Test 1 : str2 = \"%s\", str1 = \"%s\", len = %zu\n", str2, str1, len);
	char *result = ft_strnstr(str1, str2, len);
	if (result)
		printf("Resultat : Sous-chaine trouvee -> \"%s\"\n", result);
	else
		printf("Resultat : Sous-chaine non trouvee\n");

	return (0);
}

//bzero
int	main(void)
{
	char	str[] = "Bonjour, nous sommes a 42.";
	size_t	n = 10;
	size_t	i = 0;

	printf("Avant le passage de bezero : %s\n", str);
	ft_bzero(str, n);
	printf("Apres le passage de bzero a %zu : ", n);
	while (i < sizeof(str))
	{
		printf("%02x", (unsigned char)str[i]);
		i++;
	}
	printf("\n");

	return (0);
}

//memcmp
int     main(void)
{
        char    s1[] = "ttttt";
        char    s2[] = "ttttty";
		size_t 	n = 6;

        printf("Résultat : %d\n", ft_memcmp(s1, s2, n));
        return(0);
}

//memset
int main(void)
{
    char str[20] = "Hello, world!";
    char ch = '*';
    size_t n = 5;

    printf("Avant ft_memset : %s\n", str);
    
    ft_memset(str, ch, n);
    printf("Après ft_memset : %s\n", str);

    return (0);
}

//memchr
int main(void)
{
    const char *str = "Hello, world!";
    char *result;
    int ch;
    size_t n;

    ch = 'o';
    n = 10;
    result = ft_memchr(str, ch, n);
    if (result != NULL)
        printf("Caractère '%c' trouvé dans \"%s\" à la position : %ld\n", ch, str, result - str);
    else
        printf("Caractère '%c' non trouvé dans \"%s\"\n", ch, str);

    ch = 'x';
    n = 10;
    result = ft_memchr(str, ch, n);
    if (result != NULL)
        printf("Caractère '%c' trouvé dans \"%s\" à la position : %ld\n", ch, str, result - str);
    else
        printf("Caractère '%c' non trouvé dans \"%s\"\n", ch, str);

    ch = '\0';
    n = 14;
    result = ft_memchr(str, ch, n);
    if (result != NULL)
        printf("Caractère nul '\\0' trouvé dans \"%s\" à la position : %ld\n", str, result - str);
    else
        printf("Caractère nul '\\0' non trouvé dans \"%s\"\n", str);

    return (0);
}

//strncmp
int     main(void)
{
        char    s1[] = "ttttt";
        char    s2[] = "ttttty";
		size_t 	n = 6;

        printf("Résultat : %d\n", ft_strncmp(s1, s2, n));
        return(0);
}

//strrchr
int	main(void)
{
	const char *str = "Hello, world!";
	char ch;

	ch = 'o';
	char *result = ft_strrchr(str, ch);
	if (result != NULL)
		printf("Dernière occurrence du caractère '%c' trouvée dans \"%s\" à la position : %ld\n", ch, str, result - str);
	else
		printf("Caractère '%c' non trouvé dans \"%s\"\n", ch, str);

	ch = 'x';
	result = ft_strrchr(str, ch);
	if (result != NULL)
		printf("Dernière occurrence du caractère '%c' trouvée dans \"%s\" à la position : %ld\n", ch, str, result - str);
	else
		printf("Caractère '%c' non trouvé dans \"%s\"\n", ch, str);

	ch = '\0';
	result = ft_strrchr(str, ch);
	if (result != NULL)
		printf("Caractère de fin '/0' trouvé dans \"%s\" à la position : %ld\n", str, result - str);
	else
		printf("Caractère de fin '/0' non trouvé dans \"%s\"\n", str);

	return (0);
}

//strchr
int	main(void)
{
	const char *str = "Hello, world!";
	char ch;

	ch = 'o';
	char *result = ft_strchr(str, ch);
	if (result != NULL)
		printf("Caractère '%c' trouvé dans \"%s\" à la position : %ld\n", ch, str, result - str);
	else
		printf("Caractère '%c' non trouvé dans \"%s\"\n", ch, str);

	ch = 'x';
	result = ft_strchr(str, ch);
	if (result != NULL)
		printf("Caractère '%c' trouvé dans \"%s\" à la position : %ld\n", ch, str, result - str);
	else
		printf("Caractère '%c' non trouvé dans \"%s\"\n", ch, str);

	ch = '\0';
	result = ft_strchr(str, ch);
	if (result != NULL)
		printf("Caractère '%c' trouvé dans \"%s\" à la position : %ld\n", str, result - str);
	else
		printf("Caractère '%c' non trouvé dans \"%s\"\n", str);

	return (0);
}

//strlen
int     main(void)
{
        char    *str;

        str = "Bonjour, nous sommes a 42";

	printf("%zu\n", ft_strlen(str));
        return (0);
}

//isprint
int	main(void)
{
	char	*tab = "FEZzef12g   rt765gfd987)à(&=)";
	int		i = 0;
	int		u;
	
	if (tab[i] == '\0')
		printf("Il n'y à rien à lire \n");

	while (tab[i] != '\0')
	{
		u = ft_isprint(tab[i]);
		printf("Le caractere : %c = %d (1 pour print, 0 pour autre chose) \n", tab[i], u);
		i++;
	}

	return (0);
}

//isascii
int	main(void)
{
	char	*tab = "FEZzef12grt765gfd987)à(&=)";
	int		i = 0;
	int		u;
	
	if (tab[i] == '\0')
		printf("Il n'y à rien à lire \n");

	while (tab[i] != '\0')
	{
		u = ft_isascii(tab[i]);
		printf("Le caractere : %c = %d (1 pour ascii, 0 pour autre chose) \n", tab[i], u);
		i++;
	}

	return (0);
}

//isalnum
int	main(void)
{
	char	*tab = "FEZzef12grt765gfd987)à(&=)";
	int		i = 0;
	int		u;
	
	if (tab[i] == '\0')
		printf("Il n'y à rien à lire \n");

	while (tab[i] != '\0')
	{
		u = ft_isalnum(tab[i]);
		printf("Le caractere : %c = %d (1 pour alphanum, 0 pour autre chose) \n", tab[i], u);
		i++;
	}

	return (0);
}

//isdigit
int	main(void)
{
	char	*tab = "";
	int		i = 0;
	int		u;
	
	if (tab[i] == '\0')
		printf("Il n'y a rien à lire \n");

	while (tab[i] != '\0')
	{
		u = ft_isdigit(tab[i]);
		printf("Le caractere : %c = %d (1 pour digit, 0 pour autre chose) \n", tab[i], u);
		i++;
	}

	return (0);
}

//isalpha
int	main(void)
{
	char	*tab = "ERGEdsf213bfd234234ger";
	int		i = 0;
	int		u;

	if (tab[i] == '\0')
		printf("Il n'y a rien à lire \n");

	while (tab[i] != '\0')
	{
		u = ft_isalpha(tab[i]);
		printf("Le caractere : %c = %d (1 pour alpha, 0 pour autre chose) \n", tab[i], u);
		i++;
	}

	return (0);
}

//tolower
int	main(void)
{
	int		i;
	char	str[] = "GEGSDFzefzeFEZFf EZFzfzefZEFzf't''&dFZEFZ";
	
	i = 0;

	while(str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}

	printf("%s\n", str);
	return(0);
}

//toupper
int	main(void)
{
	int		i;
	char	str[] = "gregerGgergergERGergerg";
	
	i = 0;

	while(str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}

	printf("%s\n", str);
	return(0);
}

//FONCTION SUPPLEMENTAIRE

//substr
int	main(void)
{
	const char *str1 = "Bonjour, monde!";
	char *substr1 = ft_substr(str1, 8, 7);
	if (substr1)
	{
		printf("Test 1 : Extraire une sous-chaîne de \"%s\" à partir de l'index 8 avec une longueur de 7\n", str1);
		printf("Sous-chaîne extraite : \"%s\"\n", substr1);
		free(substr1);
	}
	else
	{
		printf("Erreur lors de l'extraction de la sous-chaîne\n");
	}

	const char *str2 = "Hello, world!";
	char *substr2 = ft_substr(str2, 20, 5);
	if (substr2)
	{
		printf("Test 2 : Extraire une sous-chaîne avec un index trop grand\n");
		printf("Sous-chaîne extraite : \"%s\"\n", substr2);
		free(substr2);
	}
	else
	{
		printf("Erreur lors de l'extraction de la sous-chaîne\n\n");
	}

	const char *str3 = "Libft is awesome!";
	char *substr3 = ft_substr(str3, 0, 0);
	if (substr3)
	{
		printf("Test 3 : Extraire une sous-chaîne de longueur 0\n");
		printf("Sous-chaîne extraite : \"%s\"\n", substr3);
		free(substr3);
	}
	else
	{
		printf("Erreur lors de l'extraction de la sous-chaîne\n");
	}

	const char *str4 = "";
	char *substr4 = ft_substr(str4, 0, 5);
	if (substr4)
	{
		printf("Test 4 : Extraire une sous-chaîne d'une chaîne vide\n");
		printf("Sous-chaîne extraite : \"%s\"\n", substr4);
		free(substr4);
	}
	else
	{
		printf("Erreur lors de l'extraction de la sous-chaîne\n");
	}

	return (0);
}

//strjoin
int	main(void)
{
	const char *s1 = "Bonjour";
	const char *s2 = " le monde!";
	char *result1 = ft_strjoin(s1, s2);
	if (result1)
	{
		printf("Test 1 : Joindre \"%s\" et \"%s\"\n", s1, s2);
		printf("Resultat joint : \"%s\"\n", result1);
		free(result1);
	}
	else
	{
		printf("Erreur lors de la jonction des chaines \"%s\" et \"%s\"\n", s1, s2);
	}

	const char *s3 = "";
	const char *s4 = "Bonjour tout le monde!";
	char *result2 = ft_strjoin(s3, s4);
	if (result2)
	{
		printf("Test 2 : Joindre \"%s\" et \"%s\"\n", s3, s4);
		printf("Résultat joint : \"%s\"\n", result2);
		free(result2);
	}
	else
	{
		printf("Erreur lors de la jonction des chaines \"%s\" et \"%s\"\n", s3, s4);
	}

	const char *s5 = "";
	const char *s6 = "";
	char *result3 = ft_strjoin(s5, s6);
	if (result3)
	{
		printf("Test 3 : Joindre \"%s\" et \"%s\"\n", s5, s6);
		printf("Resultat joint : \"%s\"\n", result3);
		free(result3);
	}
	else
	{
		printf("Erreur lors de la jonction des chaines \"%s\" et \"%s\"\n", s5, s6);
	}

	return (0);
}

//strtrim
int	main(void)
{
	const char *s1 = "   Hello, World!   ";
	const char *set1 = " ";
	char *result1 = ft_strtrim(s1, set1);
	if (result1)
	{
		printf("Test 1 : \"%s\" apres trim avec \"%s\" -> \"%s\"\n", s1, set1, result1);
		free(result1);
	}

	const char *s2 = "Hello, World!";
	const char *set2 = " ";
	char *result2 = ft_strtrim(s2, set2);
	if (result2)
	{
		printf("Test 2 : \"%s\" apres trim avec \"%s\" -> \"%s\"\n", s2, set2, result2);
		free(result2);
	}

	const char *s3 = "---Hello---";
	const char *set3 = "-";
	char *result3 = ft_strtrim(s3, set3);
	if (result3)
	{
		printf("Test 3 : \"%s\" apres trim avec \"%s\" -> \"%s\"\n", s3, set3, result3);
		free(result3);
	}

	const char *s4 = "&&!!!!&&&&";
	const char *set4 = "&";
	char *result4 = ft_strtrim(s4, set4);
	if (result4)
	{
		printf("Test 4 : \"%s\" apres trim avec \"%s\" -> \"%s\"\n", s4, set4, result4);
		free(result4);
	}

	return (0);
}

//split
int	main(void)
{
	const char *s = "Bonjour   tout   le   monde";
	char **result = ft_split(s, ' ');

	if (result)
	{
		int i = 0;
		while (result[i] != NULL)
		{
			printf("Mot %d : \"%s\"\n", i + 1, result[i]);
			i++;
		}

		i = 0;
		while (result[i] != NULL)
		{
			free(result[i]);
			i++;
		}
		free(result);
	}

	return (0);
}

//itoa
int	main(void)
{
	int	n1 = 12345;
	char	*result1 = ft_itoa(n1);
	if (result1)
	{
		printf("Test 1 : %d -> \"%s\"\n", n1, result1);
		free(result1);
	}
	int	n2 = -685169;
	char	*result2 = ft_itoa(n2);
	if (result2)
	{
		printf("Test 2 : %d -> \"%s\"\n", n2, result2);
		free(result2);
	}
	int	n3 = 0;
	char	*result3 = ft_itoa(n3);
	if (result3)
	{
		printf("Test 3 : %d -> \"%s\"\n", n3, result3);
		free(result3);
	}
	int	n4 = -2147483648;
	char	*result4 = ft_itoa(n4);
	if (result4)
	{
		printf("Test 4 : %d -> \"%s\"\n", n4, result4);
		free(result4);
	}
	return (0);
}
//strmapi
char	ft_totoupper(unsigned int i, char c)
{
	(void)i;
	return(ft_toupper(c));
}

int	main(void)
{
	const char *s = "hello world";
	char *result = ft_strmapi(s, ft_totoupper);

	if (result)
	{
		printf("Chaine d'origine : \"%s\"\n", s);
		printf("Chaine transformee : \"%s\"\n", result);
		free(result);
	}

	return (0);
}

//striteri
void	ft_totoupper(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

int	main(void)
{
	char str[] = "hello world";
	ft_striteri(str, ft_totoupper);

	printf("Resultat : \"%s\"\n", str);
	return (0);
}

//FONCTION FD

//putchar_fd
int	main(void)
{
	ft_putchar_fd('G', 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

//putendl_fd
int	main(void)
{
	char	*str = "Bonjour nous sommes a 42";
	ft_putendl_fd(str, 1);
	return (0);
}

//putstr_fd
int	main(void)
{
	char	*str = "Bonjour nous sommes a 42";
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

//putnbr_fd
int   main(void)
{
        ft_putnbr_fd(-78, 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(-2147483648, 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(1337, 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(9, 1);
        ft_putchar_fd('\n', 1);
        return (0);
}

// BONUS

//lstnew
int	main(void)
{
	char	*content1;
	t_list	*element1;
	t_list	*element2;
	t_list	*element3;
	int		num;

	content1 = "Bonjour";
	element1 = ft_lstnew(content1);
	if (element1 == NULL)
	{
		printf("Erreur : allocation mémoire échouée pour element1.\n");
		return (1);
	}
	printf("Test 1 - Contenu: %s\n", (char *)element1->content);
	printf("Test 1 - Pointeur next: %p (attendu: NULL)\n", element1->next);
	num = 42;
	element2 = ft_lstnew(&num);
	if (element2 == NULL)
	{
		printf("Erreur : allocation mémoire échouée pour element2.\n");
		free(element1);
		return (1);
	}
	printf("Test 2 - Contenu: %d\n", *(int *)element2->content);
	printf("Test 2 - Pointeur next: %p (attendu: NULL)\n", element2->next);
	element3 = ft_lstnew(NULL);
	if (element3 == NULL)
	{
		printf("Erreur : allocation mémoire échouée pour element3.\n");
		free(element1);
		free(element2);
		return (1);
	}
	printf("Test 3 - Contenu: %p (attendu: NULL)\n", element3->content);
	printf("Test 3 - Pointeur next: %p (attendu: NULL)\n", element3->next);
	free(element1);
	free(element2);
	free(element3);
	return (0);
}

//lstadd_front
int	main(void)
{
	t_list	*liste;
	t_list	*current;
	t_list	*element1;
	t_list	*element2;
	t_list	*element3;
	t_list	*element4;
	int		i;

	liste = NULL;
	i = 0;
	element1 = ft_lstnew("Ceci est la lst numero 1");
	element2 = ft_lstnew("Ceci est la lst numero 2");
	element3 = ft_lstnew("Ceci est la lst numero 3");
	element4 = ft_lstnew("Ceci est la lst numero 4");
	if (!element1 || !element2 || !element3 || !element4)
	{
		printf("L'allocation de memoire n'a pas fonctionne");
		free(element1);
		free(element2);
		free(element3);
		free(element4);
		return (1);
	}
	ft_lstadd_front(&liste, element1);
	ft_lstadd_front(&liste, element2);
	ft_lstadd_front(&liste, element3);
	ft_lstadd_front(&liste, element4);
	current = liste;
	while (current != NULL)
	{
		printf("Élément %d : %s\n", i, (char *)current->content);
		current = current->next;
		i++;
	}
	free(element1);
	free(element2);
	free(element3);
	free(element4);
	return (0);
}

//lstsize
int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*four;
	int		size;

	head = ft_lstnew("Premier");
	second = ft_lstnew("Deuxieme");
	third = ft_lstnew("Troisieme");
	four = ft_lstnew("Quatrieme");

	if (head)
		head->next = second;
	if (second)
		second->next = third;
	if (third)
		third->next = four;

	size = ft_lstsize(head);
	printf("Taille de la liste : %d\n", size);

	free(head);
	free(second);
	free(third);
	free(four);

	return (0);
}

//lstlast
int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*four;
	t_list	*last;

	head = ft_lstnew("Premier");
	second = ft_lstnew("Deuxième");
	third = ft_lstnew("Troisième");
	four = ft_lstnew("Quatrieme");

	if (head)
		head->next = second;
	if (second)
		second->next = third;
	if (third)
		third->next = four;

	last = ft_lstlast(head);
	if (last)
		printf("Dernier élément de la liste : %s\n", (char *)last->content);
	else
		printf("La liste est vide.\n");

	free(head);
	free(second);
	free(third);
	free(four);

	return (0);
}

//lstaddback
int	main(void)
{
	t_list	*liste;
	t_list	*current;
	t_list	*element1;
	t_list	*element2;
	t_list	*element3;
	t_list	*element4;
	int		i;

	liste = NULL;
	i = 0;
	element1 = ft_lstnew("Ceci est la lst numero 1");
	element2 = ft_lstnew("Ceci est la lst numero 2");
	element3 = ft_lstnew("Ceci est la lst numero 3");
	element4 = ft_lstnew("Ceci est la lst numero 4");
	if (!element1 || !element2 || !element3 || !element4)
	{
		printf("L'allocation de memoire n'a pas fonctionne");
		free(element1);
		free(element2);
		free(element3);
		free(element4);
		return (1);
	}
	ft_lstadd_back(&liste, element1);
	ft_lstadd_back(&liste, element2);
	ft_lstadd_back(&liste, element3);
	ft_lstadd_back(&liste, element4);
	current = liste;
	while (current != NULL)
	{
		printf("Élément %d : %s\n", i, (char *)current->content);
		current = current->next;
		i++;
	}
	free(element1);
	free(element2);
	free(element3);
	free(element4);
	return (0);
}

//lstdelone

int	main(void)
{
	t_list	*element;

	element = ft_lstnew(malloc(20));
	if (!element || !element->content)
	{
		printf("Échec de l'allocation de mémoire.\n");
		free(element);
		return (1);
	}

	ft_lstdelone(element, free);
	printf("L'élément a été supprimé.\n");

	return (0);
}

//lstclear

int	main(void)
{
	t_list	*element;

	element = ft_lstnew(malloc(20));
	if (!element || !element->content)
	{
		printf("Échec de l'allocation de mémoire.\n");
		free(element);
		return (1);
	}

	ft_lstclear(&element, free);
	printf("L'élément a été supprimé.\n");

	return (0);
}

//lstiter
int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*four;

	head = ft_lstnew("Premier");
	second = ft_lstnew("Deuxieme");
	third = ft_lstnew("Troisieme");
	four = ft_lstnew("Quatrieme");
	if (head)
		head->next = second;
	if (second)
		second->next = third;
	if (third)
		third->next = four;
	ft_lstiter(head, (void (*)(void *))printf);
	
	free(head);
	free(second);
	free(third);
	free(four);

	return (0);
}

//lstmap
int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*four;
	t_list	*new_liste;

	head = ft_lstnew("Premiere element");
	second = ft_lstnew("Deuxieme element");
	third = ft_lstnew("Troisieme element");
	four = ft_lstnew("Quatrieme element");
	if (head)
		head->next = second;
	if (second)
		second->next = third;
	if (third)
		third->next = four;
	new_liste = ft_lstmap(head, (void *(*)(void *))ft_strdup, free);
	t_list	*temp = new_liste;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	free(head);
	free(second);
	free(third);
	free(four);
	free(new_liste);
	return (0);
}