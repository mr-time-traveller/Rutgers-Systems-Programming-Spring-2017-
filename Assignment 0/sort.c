#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
	char *data;
	struct Node* next;
}Node;

Node * listCreation(char* head)
{

	if(head == NULL || head == 0 || strlen(head) <= 0)
	{
		printf("Empty input\n");
		return NULL;
	}

	else
	{
		Node *temp;
		Node * before;
		Node * after;
		char* newarray = head;
		Node* inp = NULL;
		int count = 0;
		int j = 0;

	while(*head != '\0')
	{
		if(isalpha(*newarray))
		{
			count++;
			newarray++;
		}

		else
		{	
			if(count > 0)
			{
				Node* newNode = malloc(sizeof(Node));
				newNode->data = malloc(count);
				strncpy(newNode->data,head,count);

				if(inp == NULL)
				{
					newNode->next = inp;
					inp = newNode;
				}

				else
				{
					
					temp = inp;
					before = inp;
				
					while(temp != NULL)
					{
						int c = strcmp(temp->data, newNode->data);
							
							if(c >= 0)
							{
								newNode->next = temp;

								if(temp == inp)
								{
									inp = newNode;
								}
								
								else
								{
									before->next = newNode;
								}
								break;
							}

							else
							{
								before = temp;
								temp = temp->next;
							}
						}
						
						if (temp == NULL)
						{
							newNode->next = temp;
							before->next = newNode;
						}
					}
				}
			newarray++;
			head = newarray;
			count = 0;
		}
	}
	return inp;
}
}

void printList(Node * fNode)
{
	printf("%s\n",fNode->data);
	if (fNode->next == NULL)
	{
		return;
	}
	printList(fNode->next);

}

int main(int argc, char ** argv)
{
	if (argc != 2) {
        printf("Incorrect number of arguments supplied.\n"); 
        printf("Usage: \"./pointersorter [alphabetic-tokens]\"\n");
        return 1; 
    } 
	
		char *head;
		Node *output = NULL;
		const char *temp = argv[1];

		head = malloc(sizeof(char)*strlen(temp));
		strcpy(head,temp);
		output = listCreation(head);
		printList(output);
		free(output);
		return 0;
	}
	



