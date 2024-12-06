#include<stdio.h>
#include<string.h>

// 1
struct Employee
{
    int id;
    char name[100];
    char sex[10];
    int birthyear;
    char phoneNumber[10];
    double salary;
};

void printInfor(struct Employee e){
    printf("Employee %d:\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Sex: %s\n", e.sex);
    printf("Birth Year: %d\n", e.birthyear);
    printf("Phone Number: %s\n", e.phoneNumber);
    printf("Salary: %.2f\n\n", e.salary);
}

// 2
void define10Employees(struct Employee employees[10]){
    employees[0].id = 1; 
    strcpy(employees[0].name, "Alice"); 
    strcpy(employees[0].sex, "Female"); 
    employees[0].birthyear = 1995; 
    strcpy(employees[0].phoneNumber, "123456789"); 
    employees[0].salary = 5000.00;

    employees[1].id = 2; 
    strcpy(employees[1].name, "Bob"); 
    strcpy(employees[1].sex, "Male"); 
    employees[1].birthyear = 1990; 
    strcpy(employees[1].phoneNumber, "987654321"); 
    employees[1].salary = 6000.00;

    employees[2].id = 3; 
    strcpy(employees[2].name, "Charlie"); 
    strcpy(employees[2].sex, "Male"); 
    employees[2].birthyear = 1985; 
    strcpy(employees[2].phoneNumber, "123123123"); 
    employees[2].salary = 5500.00;

    employees[3].id = 4; 
    strcpy(employees[3].name, "Diana"); 
    strcpy(employees[3].sex, "Female"); 
    employees[3].birthyear = 1993; 
    strcpy(employees[3].phoneNumber, "321321321"); 
    employees[3].salary = 5800.00;

    employees[4].id = 5; 
    strcpy(employees[4].name, "Eve"); 
    strcpy(employees[4].sex, "Female"); 
    employees[4].birthyear = 1998; 
    strcpy(employees[4].phoneNumber, "456456456"); 
    employees[4].salary = 6100.00;

    employees[5].id = 6; 
    strcpy(employees[5].name, "Frank"); 
    strcpy(employees[5].sex, "Male"); 
    employees[5].birthyear = 1987; 
    strcpy(employees[5].phoneNumber, "789789789"); 
    employees[5].salary = 5200.00;

    employees[6].id = 7; 
    strcpy(employees[6].name, "Grace"); 
    strcpy(employees[6].sex, "Female"); 
    employees[6].birthyear = 1991; 
    strcpy(employees[6].phoneNumber, "987987987"); 
    employees[6].salary = 6300.00;

    employees[7].id = 8; 
    strcpy(employees[7].name, "Hank"); 
    strcpy(employees[7].sex, "Male"); 
    employees[7].birthyear = 1983; 
    strcpy(employees[7].phoneNumber, "123987123"); 
    employees[7].salary = 4900.00;

    employees[8].id = 9; 
    strcpy(employees[8].name, "Ivy"); 
    strcpy(employees[8].sex, "Female"); 
    employees[8].birthyear = 1996; 
    strcpy(employees[8].phoneNumber, "456123456"); 
    employees[8].salary = 5400.00;

    employees[9].id = 10; 
    strcpy(employees[9].name, "Jack"); 
    strcpy(employees[9].sex, "Male"); 
    employees[9].birthyear = 1989; 
    strcpy(employees[9].phoneNumber, "789456123"); 
    employees[9].salary = 4700.00;
}

// 3
void printEmployees(struct Employee employees[], int size){
    printf("information of 10 employees\n");
    for (int i = 0; i < size; i++){
        printf("Employee %d:\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Sex: %s\n", employees[i].sex);
        printf("Birth Year: %d\n", employees[i].birthyear);
        printf("Phone Number: %s\n", employees[i].phoneNumber);
        printf("Salary: %.2f\n\n", employees[i].salary);
    }
}

// 4
struct Employee* findEmployee(struct Employee employees[],int size, int id){
    for (int i = 0; i < size; i++){
        if (employees[i].id == id)
            return &employees[i];
    }
    return NULL;
}

// 5
void countGender(struct Employee employees[], int size){
    int male = 0, female = 0;
    for(int i = 0; i < size; i++){
        if (strcmp(employees[i].sex, "Male") == 0)
            male++;
        else
            female++;
    }
    printf("Male: %d, Female: %d\n", male, female);
}

// 6
void sortByBirthYear(struct Employee employees[], int size){
    for(int i = 0; i < size - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < size; j++){
            if (employees[min_index].birthyear > employees[j].birthyear)
                min_index = j;
        }
        struct Employee temp = employees[i];
        employees[i] = employees[min_index];
        employees[min_index] = temp;
    }
}

// 7
void sortBySalary(struct Employee employees[], int size){
    for(int i = 0; i < size - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < size; j++){
            if (employees[min_index].salary > employees[j].salary)
                min_index = j;
        }
        struct Employee temp = employees[i];
        employees[i] = employees[min_index];
        employees[min_index] = temp;
    }
}

// 8
struct Employee findMaxSalary(struct Employee employees[], int size){
    int max_salary = employees[0].salary;
    struct Employee e = employees[0];
    for(int i = 0; i < size; i++){
        if(employees[i].salary > max_salary){
            max_salary = employees[i].salary;
            e = employees[i];
        }
    }
    return e;
}

// 9
struct Employee findYoungest(struct Employee employees[], int size){
    int youngest = (int)employees[0].birthyear;
    struct Employee e = employees[0];
    for(int i = 0; i < size; i++){
        if ((int)employees[i].birthyear > youngest)
        {
            youngest = (int)employees[i].birthyear;
            e = employees[i];
        }
    }
    return e;
}

// 10
void deleteEmployee(struct Employee employees[], int *size, int id){
    int indexDelete = -1;
    
    for(int i = 0; i < *size; i++){
        if (employees[i].id == id){
            indexDelete = i;
            break;
        }
    }

    if (indexDelete != -1){
        for(int i = indexDelete; i < *size - 1; i++){
            employees[i] = employees[i+1];
        }
        *size -= 1;
        printf("Delete successfully !\n");
    }else
        printf("This persion does not exist !\n");
}


int main(){
    // 2
    struct Employee employees[10];
    int size = 10;
    define10Employees(employees);

    // 3
    // printEmployees(employees);

    // // 4
    // struct Employee* e = findEmployee(employees, size, 1);
    // if (e != NULL) {
    //     printf("Employee found:\n");
    //     printInfor(*e);
    // } else {
    //     printf("Employee not found.\n");
    // }
    
    // 5
    // countGender(employees, size);
    
    // 6
    // printf("Employees after sort by BirthYear\n");
    // sortByBirthYear(employees, size);
    // printEmployees(employees);

    // 7
    // printf("Employees after sort by Salary\n");
    // sortBySalary(employees, size);
    // printEmployees(employees);

    // 8
    // struct Employee e = findMaxSalary(employees, size);
    // printInfor(e);

    // 9
    // struct Employee e = findYoungest(employees, size);
    // printInfor(e);

    // 10
    deleteEmployee(employees, &size, 11);
    printEmployees(employees, size);

    return 0;
}