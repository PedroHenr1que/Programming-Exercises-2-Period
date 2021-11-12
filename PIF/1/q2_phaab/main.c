#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dadosClientes{
	int accountId;
	char name[15];
	char surname[15];
	float balance;
	struct dadosClientes *next;
};


struct Clients{
	struct dadosClientes *firstNode;
};

void addClient(int accountId, char *clientName, char *clientSurname, float balance, struct Clients *organization, int i);
void transactionsOperations(char operation, struct Clients *organization, int accountId, float value);
void createDebtorsArchive(struct Clients *organization);
void pop(struct Clients *organization);

int main(void)
{
	FILE *clientsArchive, *transactionsArchive;
	int accountId;
	char name[15];
	char surname[15];
	float balance;
	struct dadosClientes *firstNode;
    	struct Clients *organization;
	int count = 0;

	organization = (struct Clients *)malloc(sizeof(struct Clients));
    	firstNode = (struct dadosClientes *)malloc(sizeof(struct dadosClientes));
    	organization->firstNode = firstNode;

	clientsArchive = fopen("CLIENTES.txt", "r");
	while (fscanf(clientsArchive, "%d%s%s%f", &accountId, name, surname, &balance) != EOF) {

		addClient(accountId, name, surname, balance, organization, count);
		count++;
	}
	fclose(clientsArchive);

	char operation;
	float value;

	transactionsArchive = fopen("TRANSACTIONS.txt", "r");
	while (fscanf(transactionsArchive, "%d %c %f", &accountId, &operation, &value) != EOF) {

		transactionsOperations(operation, organization, accountId, value);
	}
	fclose(transactionsArchive);

	createDebtorsArchive(organization);

	pop(organization);
}


void addClient(int accountId, char *clientName, char *clientSurname, float balance, struct Clients *organization, int i)
{
	struct dadosClientes *new, *lastClient;

	lastClient = organization->firstNode;
	new = (struct dadosClientes *)malloc(sizeof(struct dadosClientes));

	if (i == 0) {
		lastClient->accountId = accountId;
		lastClient->balance = balance;
		strncpy(lastClient->name, clientName, 15);
		strncpy(lastClient->surname, clientSurname, 15);
		lastClient->next = NULL;
	} else {

		while (lastClient->next != NULL) {
			lastClient = lastClient->next;
		}

		strncpy(new->name, clientName, 15);
		strncpy(new->surname, clientSurname, 15);
		new->balance = balance;
		new->accountId = accountId;
		new->next = NULL;
		lastClient->next = new;
	}
}


void transactionsOperations(char operation, struct Clients *organization, int accountId, float value)
{
	struct dadosClientes *client;
	int condition = 1;
	client = organization->firstNode;

	while (client != NULL && condition) {
		if (client->accountId == accountId) {
			if (operation == '+') {
				client->balance += value;
			} else {
				client->balance -= value;
			}
			condition= 0;
		}
		client = client->next;
	}
}


void createDebtorsArchive(struct Clients *organization)
{
	struct dadosClientes *client;
	FILE *debtorsArchive;
	client = organization->firstNode;
	
	debtorsArchive = fopen("DEVEDORES.txt", "w");
	while (client != NULL) {
		if (client->balance < 0) {
			fprintf(debtorsArchive, "%d %s %s %0.2f\n", client->accountId, client->name, client->surname, client->balance);
		}
		client = client->next;
	}
	fclose(debtorsArchive);
}


void pop(struct Clients *organization)
{
	struct dadosClientes *aux, *last;

	aux = organization->firstNode;

	while (aux != NULL) {
		last = aux;
		aux = aux->next;
		free(last);
	}

	free(organization);
}