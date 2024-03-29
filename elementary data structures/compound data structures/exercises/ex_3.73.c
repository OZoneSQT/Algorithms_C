#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node
{
  int v;
  link next;
};

link new(int v, link next)
{
  link x = malloc(sizeof *x);
  x->v = v;
  x->next = next;
  return x;
}

void print_list(link t, int x)
{
  printf("%d - ", x);
  while (t != NULL)
    {
      printf("%d ", t->v);
      t = t->next;
    }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int i, j, V = atoi(argv[1]);
  link *adj;

  adj = malloc(V * sizeof(link*));
  for (i = 0; i < V; i++)
    adj[i] = NULL;
  printf("Enter the edges: ");
  while (scanf("%d %d\n", &i, &j) == 2)
    {
      adj[j] = new(i, adj[j]);
      adj[i] = new(j, adj[i]);
    }
  for (i = 0; i < V; i++)
    print_list(adj[i], i);
  
  return 0;
}
