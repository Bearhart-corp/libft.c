/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auto-generator                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31                                   #+#    #+#             */
/*   Updated: 2025/10/31                                   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_BOLD    "\033[1m"

static int g_error_count = 0;
static int g_test_errors = 0;
static char g_current_test[100];

static void h_puts(const char *s) { if (s) write(1, s, (size_t)strlen(s)); }
static void h_putendl(const char *s) { h_puts(s); write(1, "\n", 1); }
static void del(void *content){(void)content;}
static void f(void *content)
<<<<<<< HEAD
{*(int *)content *= 2;}
=======
{
	*(int *)content = *(int *)content * 2;
}
>>>>>>> 0a0f5ff (ajout de printf maison)
static void *ff(void *content)
{
	int *buf = malloc(sizeof(int));
	*buf = *(int *)content * 2;
	return (buf);
}

#define TEST(name) \
	do { \
		g_test_errors = 0; \
		size_t _n = strlen(name); \
		if (_n >= sizeof(g_current_test)) _n = sizeof(g_current_test)-1; \
		memcpy(g_current_test, name, _n); \
		g_current_test[_n] = '\0'; \
	} while(0)

#define PASS(test) do {(void)(test);} while(0)

#define FAIL(test) \
	do { \
		if (g_test_errors == 0) { \
			h_puts("\n" COLOR_YELLOW "=== Testing "); \
			h_puts(g_current_test); \
			h_puts(" ===" COLOR_RESET "\n"); \
		} \
		h_puts(COLOR_RED "✗ "); \
		h_puts(test); \
		h_puts(" FAILED" COLOR_RESET "\n"); \
		g_error_count++; \
		g_test_errors++; \
	} while(0)

#define CHECK(cond, msg) do { if (!(cond)) { FAIL(msg); } else { PASS(msg); } } while(0)

static void print_test_success(const char *name)
{
	if (g_test_errors == 0) {
		h_puts(COLOR_GREEN "✓ ");
		h_puts(name);
		h_puts(COLOR_RESET "\n");
	}
}
void test_ft_isalpha(void)
{
	TEST("ft_isalpha");
	CHECK(ft_isalpha('a') != 0, "Lowercase letter");
	CHECK(ft_isalpha('Z') != 0, "Uppercase letter");
	CHECK(ft_isalpha('0') == 0, "Digit");
	CHECK(ft_isalpha(' ') == 0, "Space");
	CHECK(ft_isalpha(128) == 0, "Non-ASCII");
	CHECK(ft_isalpha('@') == 0, "Before A");
	CHECK(ft_isalpha('[') == 0, "After Z");
	CHECK(ft_isalpha('`') == 0, "Before a");
	CHECK(ft_isalpha('{') == 0, "After z");
	print_test_success("ft_isalpha");
}
void test_ft_isdigit(void)
{
	TEST("ft_isdigit");
	CHECK(ft_isdigit('0') != 0, "Digit 0");
	CHECK(ft_isdigit('9') != 0, "Digit 9");
	CHECK(ft_isdigit('a') == 0, "Letter");
	CHECK(ft_isdigit('/') == 0, "Before 0");
	CHECK(ft_isdigit(':') == 0, "After 9");
	print_test_success("ft_isdigit");
}
void test_ft_isalnum(void)
{
	TEST("ft_isalnum");
	CHECK(ft_isalnum('a') != 0, "Lowercase letter");
	CHECK(ft_isalnum('Z') != 0, "Uppercase letter");
	CHECK(ft_isalnum('5') != 0, "Digit");
	CHECK(ft_isalnum('!') == 0, "Special char");
	print_test_success("ft_isalnum");
}
void test_ft_isascii(void)
{
	TEST("ft_isascii");
	CHECK(ft_isascii(0) != 0, "Value 0");
	CHECK(ft_isascii(127) != 0, "Value 127");
	CHECK(ft_isascii(128) == 0, "Value 128");
	CHECK(ft_isascii(-1) == 0, "Value -1");
	print_test_success("ft_isascii");
}
void test_ft_isprint(void)
{
	TEST("ft_isprint");
	CHECK(ft_isprint(' ') != 0, "Space");
	CHECK(ft_isprint('~') != 0, "Tilde");
	CHECK(ft_isprint(31) == 0, "Control char");
	CHECK(ft_isprint(127) == 0, "DEL");
	print_test_success("ft_isprint");
}
void test_ft_strlen(void)
{
	TEST("ft_strlen");
	CHECK(ft_strlen("") == 0, "Empty string");
	CHECK(ft_strlen("Hello") == 5, "Hello");
	CHECK(ft_strlen("Hello World!") == 12, "Hello World!");
	print_test_success("ft_strlen");
}
void test_ft_memset(void)
{
	TEST("ft_memset");
	char b1[10], b2[10];
	memset(b1, 'A', 10);
	memset(b2, 'x', 10); /* juste pour diverger avant de tester */
	ft_memset(b2, 'A', 10);
	CHECK(memcmp(b1, b2, 10) == 0, "Fill with 'A'");
	print_test_success("ft_memset");
}
void test_ft_bzero(void)
{
	TEST("ft_bzero");
	char b[6] = "abcde";
	ft_bzero(b, 3);
	CHECK(b[0]==0 && b[1]==0 && b[2]==0 && b[3]=='d' && b[4]=='e', "Zero first 3");
	print_test_success("ft_bzero");
}
void test_ft_memcpy(void)
{
	TEST("ft_memcpy");
	char src[]="Hello";
	char d1[10], d2[10];
	memcpy(d1, src, 6);
	ft_memcpy(d2, src, 6);
	CHECK(memcmp(d1,d2,6)==0, "Copy 6 bytes");
	print_test_success("ft_memcpy");
}
void test_ft_memmove(void)
{
	TEST("ft_memmove");
	char s1[16]="0123456789";
	char s2[16]="0123456789";
	memmove(s1+2,s1,5);
	ft_memmove(s2+2,s2,5);
	CHECK(memcmp(s1,s2,16)==0, "Overlap forward");
	print_test_success("ft_memmove");
}
void test_ft_strlcpy(void)
{
	TEST("ft_strlcpy");
	char d[8]; size_t r = ft_strlcpy(d,"Hello",sizeof d);
	CHECK(r==5 && strcmp(d,"Hello")==0, "Basic");
	print_test_success("ft_strlcpy");
}
void test_ft_strlcat(void)
{
	TEST("ft_strlcat");
	char d[12]="Hi";
	size_t r = ft_strlcat(d," There",sizeof d);
	CHECK(r==8 && strcmp(d,"Hi There")==0, "Concat");
	print_test_success("ft_strlcat");
}
void test_ft_toupper(void)
{
	TEST("ft_toupper");
	CHECK(ft_toupper('a')=='A', "a->A");
	CHECK(ft_toupper('1')=='1', "digit unchanged");
	print_test_success("ft_toupper");
}
void test_ft_tolower(void)
{
	TEST("ft_tolower");
	CHECK(ft_tolower('A')=='a', "A->a");
	CHECK(ft_tolower('1')=='1', "digit unchanged");
	print_test_success("ft_tolower");
}
void test_ft_strchr(void)
{
	TEST("ft_strchr");
	char s[]="Hello";
	CHECK(ft_strchr(s,'H')==s, "first char");
	CHECK(ft_strchr(s,'\0')==s+5, "NUL");
	print_test_success("ft_strchr");
}
void test_ft_strrchr(void)
{
	TEST("ft_strrchr");
	char s[]="Hello";
	CHECK(ft_strrchr(s,'l')==s+3, "last l");
	print_test_success("ft_strrchr");
}
void test_ft_strncmp(void)
{
	TEST("ft_strncmp");
	CHECK(ft_strncmp("abc","abd",2)==0, "prefix eq");
	CHECK(ft_strncmp("abc","abd",3)<0, "less");
	print_test_success("ft_strncmp");
}
void test_ft_memchr(void)
{
	TEST("ft_memchr");
	char s[]="abc\0xyz";
	CHECK(ft_memchr(s,'\0',7)==s+3, "find NUL");
	print_test_success("ft_memchr");
}
void test_ft_memcmp(void)
{
	TEST("ft_memcmp");
	CHECK(ft_memcmp("abc","abc",3)==0, "eq");
	CHECK(ft_memcmp("ab\xff","ab\x00",3)>0, "unsigned compare");
	print_test_success("ft_memcmp");
}
void test_ft_strnstr(void)
{
	TEST("ft_strnstr");
	char h[]="Hello World";
	CHECK(ft_strnstr(h,"World",11)==h+6, "find");
	CHECK(ft_strnstr(h,"World",8)==NULL, "too short");
	print_test_success("ft_strnstr");
}
void test_ft_atoi(void)
{
	TEST("ft_atoi");
	CHECK(ft_atoi("42")==42, "pos");
	CHECK(ft_atoi("   -42")==-42, "neg");
	print_test_success("ft_atoi");
}
void test_ft_calloc(void)
{
	TEST("ft_calloc");
	int *p=(int*)ft_calloc(5,sizeof *p);
	CHECK(p!=NULL, "alloc ok");
	int ok=1; for(int i=0;i<5;i++) if(p[i]!=0) ok=0;
	CHECK(ok, "zeroed");
	free(p);
	print_test_success("ft_calloc");
}
void test_ft_strdup(void)
{
	TEST("ft_strdup");
	char *s=ft_strdup("Hello");
	CHECK(strcmp(s,"Hello")==0, "dup");
	free(s);
	print_test_success("ft_strdup");
}
void test_ft_substr(void)
{
	TEST("ft_substr");
	char *s=ft_substr("Hello World",6,5);
	CHECK(strcmp(s,"World")==0, "substr");
	free(s);
	print_test_success("ft_substr");
}
void test_ft_strjoin(void)
{
	TEST("ft_strjoin");
	char *s=ft_strjoin("Hello"," World");
	CHECK(strcmp(s,"Hello World")==0, "join");
	free(s);
	print_test_success("ft_strjoin");
}
void test_ft_strtrim(void)
{
	TEST("ft_strtrim");
	char *s=ft_strtrim("   Hello   "," ");
	CHECK(strcmp(s,"Hello")==0, "trim space");
	free(s);
	print_test_success("ft_strtrim");
}
void test_ft_split(void)
{
    TEST("ft_split");
    char **t = ft_split("a b c", ' ');
    CHECK(t && t[0] && t[1] && t[2] && !t[3], "split 3");
    if (t) {
        for (int i = 0; t[i]; i++) {
            free(t[i]);
        }
        free(t);
    }
    print_test_success("ft_split");
}
void test_ft_itoa(void)
{
	TEST("ft_itoa");
	char *s=ft_itoa(-2147483648);
	CHECK(strcmp(s,"-2147483648")==0, "INT_MIN");
	free(s);
	print_test_success("ft_itoa");
}
static char t_strmapi(unsigned int i, char c){ return (char)(c+i); }
void test_ft_strmapi(void)
{
	TEST("ft_strmapi");
	char *s=ft_strmapi("abc", t_strmapi);
	CHECK(strcmp(s,"ace")==0, "map+i");
	free(s);
	print_test_success("ft_strmapi");
}
static void t_striteri(unsigned int i, char *c){ *c=(char)(*c+i); }
void test_ft_striteri(void)
{
	TEST("ft_striteri");
	char s[]="abc";
	ft_striteri(s,t_striteri);
	CHECK(strcmp(s,"ace")==0, "iteri+i");
	print_test_success("ft_striteri");
}
void test_ft_putchar_fd(void)
{
	TEST("ft_putchar_fd");
	int fd=open("/tmp/test_putchar.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	CHECK(fd>=0,"open");
	ft_putchar_fd('A',fd); ft_putchar_fd('B',fd);
	close(fd);
	char b[8]; fd=open("/tmp/test_putchar.txt",O_RDONLY);
	ssize_t n=read(fd,b,8); if(n<0) n=0; b[n]=0; close(fd); unlink("/tmp/test_putchar.txt");
	CHECK(strcmp(b,"AB")==0,"content");
	print_test_success("ft_putchar_fd");
}
void test_ft_putstr_fd(void)
{
	TEST("ft_putstr_fd");
	int fd=open("/tmp/test_putstr.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	CHECK(fd>=0,"open");
	ft_putstr_fd("Hello",fd);
	close(fd);
	char b[8]; fd=open("/tmp/test_putstr.txt",O_RDONLY);
	ssize_t n=read(fd,b,8); if(n<0) n=0; b[n]=0; close(fd); unlink("/tmp/test_putstr.txt");
	CHECK(strcmp(b,"Hello")==0,"content");
	print_test_success("ft_putstr_fd");
}
void test_ft_putendl_fd(void)
{
	TEST("ft_putendl_fd");
	int fd=open("/tmp/test_putendl.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	CHECK(fd>=0,"open");
	ft_putendl_fd("Hello",fd);
	close(fd);
	char b[16]; fd=open("/tmp/test_putendl.txt",O_RDONLY);
	ssize_t n=read(fd,b,16); if(n<0) n=0; b[n]=0; close(fd); unlink("/tmp/test_putendl.txt");
	CHECK(strcmp(b,"Hello\n")==0,"content");
	print_test_success("ft_putendl_fd");
}
void test_ft_putnbr_fd(void)
{
	TEST("ft_putnbr_fd");
	int fd=open("/tmp/test_putnbr.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	CHECK(fd>=0,"open");
	ft_putnbr_fd(-42,fd);
	close(fd);
	char b[16]; fd=open("/tmp/test_putnbr.txt",O_RDONLY);
	ssize_t n=read(fd,b,16); if(n<0) n=0; b[n]=0; close(fd); unlink("/tmp/test_putnbr.txt");
	CHECK(strcmp(b,"-42")==0,"content");
	print_test_success("ft_putnbr_fd");
}
void test_ft_lstnew(void)
{
	TEST("ft_lstnew");
	int value = 42;
	t_list *node = ft_lstnew(&value);

	CHECK(node != NULL, "Node is not NULL");
	CHECK(node->content == &value, "Content is set correctly");
	CHECK(node->next == NULL, "Next pointer is NULL");

	// Nettoyage
	free(node);

	print_test_success("ft_lstnew");
}
void test_ft_lstadd_back(void)
{
	TEST("ft_lstadd_back");
	int v1 = 1, v2 = 2;// 2 noeuds les fameux noeud-noeud ^^
	t_list *node1 = ft_lstnew(&v1);
	t_list *node2 = ft_lstnew(&v2);

	t_list *list = NULL;
	ft_lstadd_back(&list, node1);
	CHECK(list == node1, "First node added correctly");
	CHECK(list->next == NULL, "Next of first node is NULL");

	// Ajouter le deuxième noeud
	ft_lstadd_back(&list, node2);
	CHECK(list->next == node2, "Second node added correctly");
	CHECK(list->next->next == NULL, "Next of second node is NULL");

	// Nettoyage
	free(node1);
	free(node2);

	print_test_success("ft_lstadd_back");
}
void test_ft_lstadd_front(void)
{
	TEST("ft_lstadd_front");
	int v1 = 1, v2 = 2;
	t_list *node1 = ft_lstnew(&v1);
	t_list *node2 = ft_lstnew(&v2);

	t_list *list = NULL;
	ft_lstadd_front(&list, node2);
	CHECK(list == node2, "le premier c ok frate");
	CHECK(list->next == NULL, "ya rien, et cest ok !");

	ft_lstadd_front(&list, node1);
	CHECK(list == node1, "cest le nouveau premier node");
	CHECK(list->next == node2, "on retrouve notre premier node qui est 2ieme maintenant");

	free(node1);
	free(node2);
	print_test_success("ft_lstadd_front");
}
void test_ft_lstclear(void)
{
	TEST("ft_lstclear");
	int v1 = 1, v2 = 2, v3 = 3;
	t_list *node1 = ft_lstnew(&v1);
	t_list *node2 = ft_lstnew(&v2);
	t_list *node3 = ft_lstnew(&v3);

	t_list *list = NULL;
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);
	CHECK(list->next == node2 && node2->next == node3, "ya bien les 3 comperes");

	ft_lstclear(&list, &del);
	CHECK(list == NULL, "cest bien clean");
	print_test_success("ft_lstclear");
}
void test_ft_lstdelone(void)
{
	TEST("ft_lstdelone");
	int v1 = 1;
	t_list *node1 = ft_lstnew(&v1);

	t_list *list = node1;

	ft_lstdelone(node1, &del);
<<<<<<< HEAD
=======
	CHECK(node1 == NULL, "cest ok jose");
>>>>>>> 0a0f5ff (ajout de printf maison)
	print_test_success("ft_lstdelone");
}
void test_ft_lstiter(void)
{
	TEST("ft_lstiter");
	//ON VA TEST AVEC UNE FUNC QUI DOUBLE CHAQUE VALEUR
	int v1 = 1, v2 = 2, v3 = 3;
	t_list *node1 = ft_lstnew(&v1);
	t_list *node2 = ft_lstnew(&v2);
	t_list *node3 = ft_lstnew(&v3);

	t_list *list = NULL;
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	ft_lstiter(list, f);
	CHECK(*(int *)node1->content == 2 &&
			*(int *)node2->content == 4 &&
			*(int *)node3->content == 6,
			"applique f sur les 3 nodes");
	free(node1);
	free(node2);
	free(node3);
	print_test_success("ft_lstiter");
}
void test_ft_lstlast(void)
{
	TEST("ft_lstlast");
	int v1 = 1, v2 = 2, v3 = 3;
	t_list *node1 = ft_lstnew(&v1);
	t_list *node2 = ft_lstnew(&v2);
	t_list *node3 = ft_lstnew(&v3);

	t_list *list = NULL;
	t_list *vide = NULL;
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);
	
	CHECK(ft_lstlast(list) == node3, "A bien trouve le dernier");
	CHECK(ft_lstlast(vide) == NULL, "cas vide");


	free(node1);
	free(node2);
	free(node3);
	print_test_success("ft_lstlast");
}
void test_ft_lstsize(void)
{
	TEST("ft_lstsize");
	int v1 = 1, v2 = 2, v3 = 3;
	t_list *node1 = ft_lstnew(&v1);
	t_list *node2 = ft_lstnew(&v2);
	t_list *node3 = ft_lstnew(&v3);

	t_list *list = NULL;
	t_list *vide = NULL;
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);
	CHECK(ft_lstsize(list) == 3, "cas 3 node");
	CHECK(ft_lstsize(vide) == 0, "cas 0 node");

	free(node1);
	free(node2);
	free(node3);
	print_test_success("ft_lstsize");
}
void test_ft_lstmap(void)
{
	TEST("ft_lstmap");
	int v1 = 1, v2 = 2, v3 = 3;
	t_list *node1 = ft_lstnew(&v1);
	t_list *node2 = ft_lstnew(&v2);
	t_list *node3 = ft_lstnew(&v3);

	t_list *list = NULL;
	t_list *vide = NULL;
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	vide = ft_lstmap(vide, &ff, &del);
	CHECK(vide == NULL, "le cas vide");

	t_list *buf = ft_lstmap(list, &ff, &del);
	CHECK(*(int *)buf->content == *(int *)(node1->content) * 2 &&
	buf != node1,
	"le 1er node a la meme valeur *2 mais pas la meme adresse");
	buf = buf->next;

	CHECK(*(int *)buf->content == *(int *)(node2->content) * 2 &&
	buf != node2,
	"le 2ieme node a la meme valeur *2 mais pas la meme adresse");
	buf = buf->next;

	CHECK(*(int *)buf->content == *(int *)(node3->content) * 2 &&
	buf != node3,
	"le 3ieme node a la meme valeur * 2 mais pas la meme adresse");
	buf = buf->next;

	ft_lstclear(&list, &del);
	ft_lstclear(&buf,  &del);
	print_test_success("ft_lstmap");
}

int main(void)
{
	h_putendl("");
	h_puts(COLOR_CYAN COLOR_BOLD);
	h_putendl("╔════════════════════════════════════════╗");
	h_putendl("║     LIBFT TEST SUITE                   ║");
	h_putendl("╚════════════════════════════════════════╝");
	h_puts(COLOR_RESET);
	h_putendl("");
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
	test_ft_atoi();
	test_ft_calloc();
	test_ft_strdup();
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_strmapi();
	test_ft_striteri();
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
	test_ft_lstnew();
	test_ft_lstadd_back();
	test_ft_lstadd_front();
	test_ft_lstclear();
	test_ft_lstdelone();
	test_ft_lstiter();
	test_ft_lstlast();
	test_ft_lstsize();
	test_ft_lstmap();

	h_putendl("");
	h_puts(COLOR_CYAN COLOR_BOLD);
	h_putendl("╔════════════════════════════════════════╗");
	if (g_error_count == 0)
	{
		h_puts(COLOR_GREEN "║     ALL TESTS PASSED ✓                 ║\n" COLOR_CYAN);
		h_putendl("╚════════════════════════════════════════╝");
	}
	else
	{
		char buf[32];
		int len = snprintf(buf, sizeof buf, "%d", g_error_count);
		h_puts(COLOR_RED "║     TESTS FAILED: ");
		write(1, buf, (size_t)len);
		h_puts(" error(s)            ║\n" COLOR_CYAN);
		h_putendl("╚════════════════════════════════════════╝");
	}
	h_puts(COLOR_RESET);
	h_putendl("");
	return g_error_count;
}
