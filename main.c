//Omar Shoubaki 1230329 section 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define name_Len 50
#define date_Len 20


typedef struct Task {
    int id;
    char name[name_Len];
    char date[date_Len];
    double duration;
    struct Task* next;
} Task;

typedef struct Stack {
    Task* task;
    struct Stack* next;
} Stack;
Task* header = NULL;
Stack* performedTasks= NULL;
Task* undoneTasks = NULL;


Task * loadTasks();
void addTask();
void deleteTask();
void searchForATask();
void viewUnperformedTasks();
void performTask();
void undoTask();
void displayPerformedTasks();
void generateReportSummary();
void push( Task* task);
Task * pop ();
void toLowerCase(char* input);

int main(){

    int x=0;
    while(x!=10){
        printf("\nSelect an operation 1-10: \n");
        printf("1- Load tasks from file \n");
        printf("2- Add a new task \n");
        printf("3- Delete a task \n");
        printf("4- Search for a task \n");
        printf("5- View unperformed tasks \n");
        printf("6- Perform a task \n");
        printf("7- Undo last performed task \n");
        printf("8- View performed tasks \n");
        printf("9- Generate summary report \n");
        printf("10- Exit program \n");
        printf("Enter your choice: ");
        scanf("%d", &x);
        switch(x){
            case 1:header = loadTasks();
            break;

            case 2: addTask();
            break;
            case 3: deleteTask();
            break;
            case 4: searchForATask();
            break;
            case 5: viewUnperformedTasks();
            break;
            case 6: performTask();
            break;
            case 7: undoTask();
            break;
            case 8: displayPerformedTasks();
            break;
            case 9: generateReportSummary();
            break;
            case 10: printf("\nGoodluck with the rest of your day");
            break;
            default: printf("\n Please enter a number 1-10 \n");
            break;
        }



    }
}


Task * loadTasks(){
    FILE * file = fopen("tasks.txt", "r");
    if(!file){
        printf("File not found \n");
        return header;
    }
    Task* newTask= NULL;
    Task *ptr = NULL;
    char line[200];
    int id;
    char name[name_Len];
    char date[date_Len];
    double duration;
    ptr = header;
    if (ptr != NULL) {
        while (ptr->next != NULL) {
        ptr = ptr->next;
    }
}
    while(fgets(line, sizeof(line), file)){
        line[strcspn(line, "\n")] = 0;

        char *idToken = strtok(line, "#");
        char *nameToken = strtok(NULL, "#");
        char *dateToken = strtok(NULL, "#");
        char *durationToken = strtok(NULL, "#");
        id = atoi(idToken);
        strcpy(name, nameToken);
        strcpy(date, dateToken);
        duration = atof(durationToken);

        newTask = malloc(sizeof(Task));
        newTask->id= id;
        strcpy(newTask->name,name);
        strcpy(newTask->date,date);
        newTask->duration= duration;
        newTask->next = NULL;
        if(header==NULL){
            header= newTask;
            ptr= newTask;
        }
        else{
            ptr->next = newTask;
            ptr = newTask;
        }}
    fclose(file);
    printf("\nTasks loaded successfully \n");
    return header;
}


void addTask(){
    int id;
    int c = 1;

    while(c == 1){
        printf("\nEnter task ID: ");
        scanf("%d", &id);

        Task* dupe = header;
        int found = 0;
        while(dupe != NULL){
            if(dupe->id == id){
                printf("\nAnother task with the same ID exists, choose a different ID\n");
                found = 1;
                break;
            }
            dupe = dupe->next;
        }

        if(found == 0){
            c = 0;
        }
    }

    Task* newTask = malloc(sizeof(Task));
    newTask->id = id;
    printf("\nEnter task name: ");
    scanf(" %[^\n]", newTask->name);
    printf("\nEnter task due date: ");
    scanf("%s", newTask->date);
    printf("\nEnter duration: ");
    scanf("%lf", &newTask->duration);
    newTask->next = NULL;

    if(header == NULL){
        header = newTask;
    }
    else{
        Task* temp = header;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newTask;
    }

    printf("\nTask added successfully.\n");
}


void deleteTask(){
    if(header==NULL){
        printf("\nList is already empty. \n");
        return;
    }
    int id;
    printf("\nEnter the id of the task you wish to delete: ");
    scanf("%d", &id);
    Task *temp = header, *prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nTask not found \n");
        return;
    }
    if (prev == NULL) {
        header = header->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("\nTask deleted \n");
}

void searchForATask(){
    if(header!=NULL){
        int choice;
        printf("How do you want to search: \n");
        printf("1) ID \n");
        printf("2) Name \n");
        scanf("%d", &choice);
        if(choice==1){
            Task* temp = header ;
            int id;
            printf("\nEnter the id of the task you're searching for:  ");
            scanf("%d", &id);
            int c=0;
            while(temp!=NULL){
                if(temp->id == id){
                    printf("\n%d- %s %s %.1lf hours \n", temp->id, temp->name,temp->date, temp->duration);
                    c++;
                    return;
                }
                temp= temp->next;
            }
            if(c==0){
                printf("\nTask not found..\n");
            }
        }
        else if(choice==2){
            Task* temp = header;
            char name[name_Len];
            printf("\nEnter the name of the task you're searching for:  ");
            scanf(" %[^\n]", name);
            toLowerCase(name);
            int c=0;
            while(temp!=NULL){
                char x[name_Len];
                strcpy(x,temp->name);
                toLowerCase(x);
                if(strcmp(x,name)==0){
                    printf("\n%d- %s %s %.1lf \n", temp->id, temp->name,temp->date, temp->duration);
                    c++;
                    return;
                }
                temp= temp->next;
            }
            if(c==0){
                printf("\nTask not found..\n");
            }
        }
        else{
            printf("\nPlease choose either 1 or 2....\n");
        }
    }
    else{
        printf("\nList is empty..\n");
    }
}

void viewUnperformedTasks(){
    if(header==NULL){
        printf("\nNo unperformed tasks. \n");
        return;
    }
    printf("\nList of unperformed tasks: \n");
    Task * temp = header;
    while(temp!= NULL){
        printf("%d- %s %s %.1lf hours \n", temp->id, temp->name, temp->date, temp->duration);
        temp= temp->next;
    }
}

void performTask(){
    if(header==NULL){
        printf("\nNo tasks to perform..\n ");
        return;
    }
    else{
        Task * task = header;
        header= header-> next;
        task->next = NULL;
        push(task);
        printf("\n%s was moved to your finished tasks \n", task->name);
    }
}
void undoTask(){
    if(performedTasks==NULL){
        printf("\nNo tasks to undo \n");
        return;
    }
    else{
        Task* task = pop();
        task->next= NULL;

        if(header==NULL){
            header= task;
        }
        else{
            Task * temp =header;
            while(temp->next!=NULL){
                temp= temp->next;
            }
            temp->next = task;
        }

        if(undoneTasks==NULL){
            undoneTasks= task;
        }
        else{
            Task * temp =undoneTasks;
            while(temp->next!=NULL){
                temp= temp->next;
            }
            temp->next = task;
        }

        printf("\n%s was moved back to your to do list\n", task->name);
    }
}

void displayPerformedTasks(){
    if(performedTasks==NULL){
        printf("\nYou havent done any tasks\n");
        return;
    }
    else{
        printf("\nList of performed tasks: \n");
        Stack* temp = performedTasks;
        while(temp!=NULL){
            Task*x = temp->task;
            printf("\n%d- %s %s %.1lf hours \n", x->id, x->name, x->date, x->duration);
            temp= temp->next;

        }
    }


}
void generateReportSummary(){
    FILE *file= fopen("Report.txt","w");
    if(file==NULL){
        printf("\nCouldn't open Report.txt\n");
        return;
    }
    else{
        fprintf(file,"List of unperformed tasks: \n");
        Task* temp =header;
        int found = 0;
        while(temp!=NULL){
            fprintf(file,"%d- %s %s %.1lf hours\n", temp->id, temp->name, temp->date, temp->duration);
            found = 1;
            temp= temp->next;
        }
        if (!found)
            fprintf(file, "(None)\n");

        fprintf(file, "\nList of undone tasks: \n");
        temp = undoneTasks;
        found = 0;
        while(temp!=NULL){
            fprintf(file,"%d- %s %s %.1lf hours\n", temp->id, temp->name, temp->date, temp->duration);
            found = 1;
            temp= temp->next;
        }
        if (!found)
            fprintf(file, "(None)\n");

        fprintf(file,"\nList of finished tasks: \n");
        Stack*t =performedTasks;
        if (t == NULL) {
            fprintf(file, "(None)\n");
        }
        while(t!=NULL){
            Task *x= t->task;
            fprintf(file, "%d- %s %s %.1lf hours \n", x->id, x->name, x->date, x->duration);
            t= t->next;
        }
    }
    fclose(file);
    printf("\nReport was generated and ready to be checked at Report.txt \n");
}




void toLowerCase(char* input) {
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }
}

void push(Task* task) {
    Stack* performedTask = malloc(sizeof(Stack));
    performedTask->task = task;
    performedTask->next = performedTasks;
    performedTasks = performedTask;
}
Task* pop(){
    Stack * temp = performedTasks;
    performedTasks= performedTasks->next;
    Task* undone =temp-> task;
    free(temp);
    return undone;

}
