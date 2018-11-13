#define OPTIONSIZE 8

/** \brief
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

int controller_addEmployee(LinkedList* pArrayListEmployee);

int controller_editEmployee(LinkedList* pArrayListEmployee);

int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_ListEmployee(LinkedList* pArrayListEmployee);

int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

void chargeIsSuccesful(int state);

void deleteIsSuccesful(int state);

void sortIsSuccesful(int state);

void saveIsSuccesful(int state);

int controller_getIntId(int entero, int len);

int controller_valIntId(char *pString, int entero, char *pChar, int len);

int controller_searchCharacterIntId(char *pString);

int controller_searchSpaceId(char *pString);

int controller_getIntMenu(int option,int len);

int controller_valIntMenu(char *pString, int entero);

int controller_flagState(int option,int* flag1, int* flag2, int* flag3, int* flag4, LinkedList* pArrayListEmployee);

char controller_getChar(char option);

char controller_valChar(char option);
