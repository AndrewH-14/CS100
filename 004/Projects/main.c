#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define structs
typedef struct _map Map;
typedef struct _category Category;
typedef struct _business Business;

struct _map {
    char* name;
    Category* category_head;
};

struct _category {
    char* name;
    Business* business_head;
    Category* next;
};

struct _business {
    char* name;
    int num_employees;
    Business* next;
};

// Create a new map
Map* newMap(char* name) {
    Map* listMap = (Map*)malloc(sizeof(Map));
    listMap->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(listMap->name, name);
    listMap->category_head = NULL;
    return listMap;
}

// Add a category to the list in proper lexicographical order
// Returns 1 if the category is already in the map, else returns 0
int addCategory(Map* map, char* name) {
    Category* newCategory = (Category*)malloc(sizeof(Category));
    newCategory->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(newCategory->name, name);
    newCategory->business_head = NULL;
    newCategory->next = NULL;

    for (Category* cur = map->category_head; cur != NULL; cur = cur->next) {
        if (strcmp(cur->name, name) == 0) {
            return 1;
        }
    }

    if (map->category_head == NULL) {
        map->category_head = newCategory;
        return 0;
    }
    else if (strcmp(map->category_head->name, newCategory->name) > 0) {
        newCategory->next = map->category_head;
        map->category_head = newCategory;
        return 0;
    }
    else {
        Category* prev = map->category_head;
        while (prev->next != NULL) {
             if (strcmp(prev->next->name, newCategory->name) > 0) {
                 break;
             }
             prev = prev->next;
        }
        newCategory->next = prev->next;
        prev->next = newCategory;
        return 0;
    }
}

// Add a business to the map sorted by number of employees descending
// Returns 1 if the category does not exist, else returns 0
int addBusiness(Map* map, char* category, char* name, int num_employees) {
    Business* newBusiness = (Business*)malloc(sizeof(Business));
    newBusiness->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(newBusiness->name, name);
    newBusiness->num_employees = num_employees;
    newBusiness->next = NULL;
    for (Category* cur = map->category_head; cur != NULL; cur = cur->next) {
        if (strcmp(cur->name, category) == 0) {

            for (Business* curBus = cur->business_head; curBus != NULL; curBus = curBus->next) {
                if (strcmp(curBus->name, newBusiness->name) == 0) {
                    curBus->num_employees = newBusiness->num_employees;
                    return 0;
                }
            }
        
            if (cur->business_head == NULL) {
                //printf("...\n");
                cur->business_head = newBusiness;
                return 0;
            }
            else if (newBusiness->num_employees > cur->business_head->num_employees) {
                //printf("!!!\n");
                newBusiness->next = cur->business_head;
                cur->business_head = newBusiness;
                return 0;
            }
            else {
                //printf(",,,\n");
                Business* prev = cur->business_head;
                while (prev->next != NULL) {
                    if (newBusiness->num_employees > prev->next->num_employees) {
                        break;
                    }
                    prev = prev->next;
                }
                newBusiness->next = prev->next;
                prev->next = newBusiness;
                return 0;
            }
        }
    }
    return 1;
}

// Display all the categories and businesses in a map
void display(Map* map) {
    printf("%s\n", map->name);
    if (map->category_head == NULL) {
        printf("Map is empty\n");
    }
    else {
        for (Category* cur = map->category_head; cur != NULL; cur = cur->next) {
            if (cur->business_head == NULL) {
                printf("%s: Empty\n", cur->name);
            }
            else {
                printf("%s: ", cur->name);
                for (Business* curBus = cur->business_head; curBus != NULL; curBus = curBus->next) {
                    printf("%s (%d)", curBus->name, curBus->num_employees);
                    if (curBus->next != NULL) {
                        printf(", ");
                    }
                }
                printf("\n");
            }
        }
    }
}

// Remove the business from the list.
// If the category does not exists, return 1. If the business does not exists, return 2.
// Else, removes the business and return 0.
int removeBusiness(Map* map, char* category, char* name) {
    for (Category* cur = map->category_head; cur != NULL; cur = cur->next) {
        if (strcmp(cur->name, category) == 0) {

            for (Business* curBus = cur->business_head; curBus != NULL; curBus = curBus->next) {
                if (strcmp(curBus->name, name) == 0) {
                    break;
                }
                else if (curBus->next == NULL) {
                    return 2;
                }
            }


            if (strcmp(cur->business_head->name, name) == 0) {
                Business* newHead = cur->business_head->next;
                free(cur->business_head->name);
                free(cur->business_head);
                cur->business_head = newHead;
                return 0;
            }
            else {
                Business* prev = cur->business_head;

                while(prev->next != NULL) {

                    if (strcmp(prev->next->name, name) == 0) {
                        break;
                    }
                    prev = prev->next;
                }

                Business* toBeDeleted = prev->next;
                prev->next = prev->next->next;
                free(toBeDeleted->name);
                free(toBeDeleted);

                return 0;
            }
        }
    }
    return 1;
}

// Remove the category with provided name
// If the category doesn't exist, returns 1, else, removes the category and returns 0
int removeCategory(Map* map, char* name) {

    for (Category* cur = map->category_head; cur != NULL; cur = cur->next) {
        if (strcmp(cur->name, name) == 0) {
            break;
        }
        else if (cur->next == NULL) {
            return 1;
        }
    }
    
    if (strcmp(map->category_head->name, name) == 0) {
        Business* temp;
        for (Business* curBus = map->category_head->business_head; curBus != NULL; curBus = temp) {
                temp = curBus->next;
                removeBusiness(map, name, curBus->name);
        }

        Category* newHead = map->category_head->next;
        free(map->category_head->name);
        free(map->category_head);
        map->category_head = newHead;
        return 0;
    }
    else {
        Category* prev = map->category_head;

        while(prev->next != NULL) {

            if (strcmp(prev->next->name, name) == 0) {
                break;
            }
            prev = prev->next;
        }
        Business* temp;
        for (Business* curBus = prev->next->business_head; curBus != NULL; curBus = temp) {
            temp = curBus->next;
            removeBusiness(map, name, curBus->name);
        }

        Category* toBeDeleted = prev->next;
        prev->next = prev->next->next;
        free(toBeDeleted->name);
        free(toBeDeleted);
        return 0;
    }
    return 1;
}

// Returns the number of businesses in a category with at least min_employees and no more than max_employees
// Returns -1 if the category does not exist
int countBusinesses(Map* map, char* category, int min_employees, int max_employees) {
    int count = 0;
    for (Category* cur = map->category_head; cur != NULL; cur = cur->next) {
        if (strcmp(cur->name, category) == 0) {
            for (Business* curBus = cur->business_head; curBus != NULL; curBus = curBus->next) {
                if ((curBus->num_employees >= min_employees) && (curBus->num_employees <= max_employees)) {
                    count++;
                }
            }
            return count;
        }
    }
    return -1;
}

int main() {
    Map* map = newMap("TV City");

    addCategory(map, "Office");
    addBusiness(map, "Office", "Dunder Mifflin Utica", 10);

    display(map);
    printf("-----\n");

    addBusiness(map, "Office", "Dunder Mifflin Scranton", 19);

    display(map);
    printf("-----\n");
    
    addCategory(map, "Food and Drink");
    addBusiness(map, "Food and Drink", "Jasmine Dragon", 7);

    addCategory(map, "Hospitals");
    addBusiness(map, "Hospitals", "Princeton-Plainsboro Teaching Hospital", 8672);
    addBusiness(map, "Hospitals", "Seattle Grace Hospital", 6824);

    addCategory(map, "Gas");

    display(map);
    printf("-----\n");

    removeCategory(map, "Food and Drink");

    display(map);
    printf("-----\n");

    removeBusiness(map, "Hospitals", "Princeton-Plainsboro Teaching Hospital");
    
    display(map);
    printf("-----\n");

    printf("Number of very small office businesses: %d\n", countBusinesses(map, "Office", 0, 10));
}
