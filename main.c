#include"graph.h"
#include<stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
	pnode head = NULL;
	char select;
	FILE *fileIn;
	fileIn=stdin;
	select=fgetc(fileIn);
	while (select!=EOF) {
		switch (select)
		{
		case 'A': {
			build_graph_cmd(&head);
			break;
		}
		case'B': {
			insert_node_cmd2(&head);
			break;
		}
		case 'D': {
			delete_node_cmd(&head);
			
			break;
		}
		case'S':
		{
			int src, dest;
			scanf("%d", &src);
			scanf("%d", &dest);
			int temp= shortsPath_cmd(head, src, dest);
			printf("Dijsktra shortest path: %d\n",temp);
			break;
		}
		case 'T': {
			TSP_cmd(head);
			break;
		}

		}
		select=fgetc(fileIn);
		
	}
	//printGraph_cmd(head);
	deleteGraph_cmd(&head);
	return 0;
}
