#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable:4996)


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN     "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGNETA     "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET     "\x1b[0m"

// all of the FILE* pointers

FILE* pointernormal;
FILE* pointertejari;
FILE* pointeradmin;
FILE* pointercounter;
FILE* pointertime1;
FILE* pointertime2;
FILE* pointertime3;
FILE* pointermorde;
FILE* pointerhospital;

// all of the numbers we need for counting

int countcreate = 1;
int countcreaten = 1;
int num_mordegan;
int num_hospital;

// time_t variables 

time_t k;
time_t k2;
time_t t;
time_t t1, t2, t3;
time_t q;
time_t q2;
time_t n1, n2, n3;
time_t glo = time(NULL);

// 2 array for saving codes

int codsalamati1[50];
int codsalamati2[50];

// motefareghe
int helper = 0;
char grbj1[30], grbj2[30];
int i = 0;
char grbj;
int zz;
char yday[50][50];
char x[30];
char timemobtala[100][50];
char usernamevoroodi[50];
char password[50];
char homext[50];

//3 array for saving all of the times

int timesaving1[100];
int timesaving2[100][10];
int timesaving3[100][30];

// struct for saving hospitals
struct Hospital {
	char name[50];
	char city[30];
	char area[30];
};
struct Hospital hospital[101];

//string for dead people
struct mordegane_moteharek {
	char name[50];
	char familyname[50];
	char nationalcode[50];
	char username[50];
	char password[50];
};
struct mordegane_moteharek mordegan[20];

//struct for admin user

struct Admin {

	char username[1000];
	char password[1000];
	char national_code[1000];
	char email[1000];
};
//----------------------------------------------------------
struct Admin adminn = { "raise_mafia" , "192837" , "123123" ,"raise_mafia@gmail.com" };

//struct for normal user

struct normal {

	char name[50];
	char familyname[50];
	char nationalcode[50];
	char username[50];
	char password[50];
	char tkrrpassword[50];
	char email_adress[50];
	char blood_type[50];
	char  age[50];
	char hight[50];
	char  weight[50];
	int codesalamat;
	char timesabtevazeiat[10][50];
	int tsabtvazeiat;
	int onlinesalamat[11];
	char timemolaghat[50][50];
	char fardmolaghati[50][50];
	int num_molaghat;
	int code_molaghati[11];
	char placemolaghati[50][50];
	char placetimemolaghat[50][50];
	char vazeiate_molaghati[50][9];
	int num_molaghat_place;
};

struct normal usern[100];

//struct for tejari user

struct tejari {
	char name[50];
	char familyname[50];
	char nationalcode[50];
	char username[50];
	char password[50];
	char tkrrpassword[50];
	char email_adress[50];
	char mahalekar[50];
	char shahr[50];
	char mantaghe[50];
	char vazeiat[20];
};

struct tejari user[100];

// three string for forget password function
char emailfrgt[50];
char usernamefrgt[50];
char kodemelifrgt[50];

// functions

void log_in(void);
void forget_password(void);
void graphic_name();
void create_normal(void);
void create_tejari(void);
void menu_u1tjr(int a);
void menu_u1nrml(int a);
void health_situation(int a);
void menu_admin();
void editu1nrml(int a);
void editu1tjr(int a);
void editadmin();
void password_to_star(char str[50]);
void homextmenu(int a);
void adminhomextmenu();
void homextmenutejari(int id);
void coronavirouslearning(void);
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(void)
{
	if (fopen("tejariuser.txt", "r+") == NULL)
		pointertejari = fopen("tejariuser.txt", "w");
	if (fopen("adminuser.txt", "r+") == NULL)
		pointertejari = fopen("adminuser.txt", "w");
	if (fopen("normaluser.txt", "r+") == NULL)
		pointertejari = fopen("normaluser.txt", "w");
	if (fopen("counter.txt", "r+") == NULL)
		pointertejari = fopen("counter.txt", "w");
	if (fopen("time_saving.txt", "r+") == NULL)
		pointertejari = fopen("time_saving.txt", "w");
	if (fopen("time_saving2.txt", "r+") == NULL)
		pointertejari = fopen("time_saving2.txt", "w");
	if (fopen("time_saving3.txt", "r+") == NULL)
		pointertejari = fopen("time_saving3.txt", "w");
	if (fopen("mordeusers.txt", "r+") == NULL)
		pointertejari = fopen("mordeusers.txt", "w");
	if (fopen("hospital.txt", "r+") == NULL)
		pointertejari = fopen("hospital.txt", "w");


	pointertejari = fopen("tejariuser.txt", "r+");
	pointeradmin = fopen("adminuser.txt", "r+");
	pointernormal = fopen("normaluser.txt", "r+");
	pointercounter = fopen("counter.txt", "r+");
	pointertime1 = fopen("time_saving.txt", "r+");
	pointertime2 = fopen("time_saving2.txt", "r+");
	pointertime3 = fopen("time_saving3.txt", "r+");
	pointermorde = fopen("mordeusers.txt", "r+");
	pointerhospital = fopen("hospital.txt", "r+");


	user[0] = { "mahdi","banihashem","121212121212","mahdi_mo_ood","255255","255255","mahdi_mo_ood_@gmail.com","sedeh_state","isfahan","khoozan","Red" };
	usern[0] = { "mir_mohsen", "karoobinejad", "4257788898", "mgh_2002", "14001400", "14001400", "mirmohsen_karoobinejad1388@gmail.com", "O-", "18", "176", "69", 1 };

	fscanf(pointercounter, "%d%d%d%d", &countcreaten, &countcreate, &num_mordegan, &num_hospital);

	if (countcreate == 0) {
		countcreate++;
	}
	if (countcreaten == 0) {
		countcreaten++;
	}

	fread(&mordegan, sizeof(struct mordegane_moteharek), num_mordegan, pointermorde);

	fread(&hospital, sizeof(struct Hospital), num_hospital, pointerhospital);

	fread(&usern, sizeof(struct normal), countcreaten, pointernormal);

	fread(&user, sizeof(struct tejari), countcreate, pointertejari);

	fread(&adminn, sizeof(struct Admin), 1, pointeradmin);

	int i, j;
	for (i = 0; i < countcreaten; i++) {
		fscanf(pointertime1, "%d", &timesaving1[i]);
	}
	for (i = 0; i < countcreaten; i++) {
		for (j = 0; j <= countcreaten; j++)
			fscanf(pointertime2, "%d", &timesaving2[i][j]);
	}
	for (i = 0; i < countcreaten; i++) {
		for (j = 0; j <= usern[i].num_molaghat_place; j++)
			fscanf(pointertime3, "%d", &timesaving3[i][j]);
	}
	fcloseall();


	graphic_name();

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void graphic_name(void) {
	pointernormal = fopen("normaluser.txt", "w");
	pointertejari = fopen("tejariuser.txt", "w");
	pointercounter = fopen("counter.txt", "w");

	fprintf(pointercounter, "%d %d %d %d", countcreaten, countcreate, num_mordegan, num_hospital);
	fwrite(&usern, sizeof(struct normal), countcreaten + 1, pointernormal);
	fwrite(&user, sizeof(struct tejari), countcreate + 1, pointertejari);
	fcloseall();
	system("cls");
	printf(ANSI_COLOR_RED"\n\n\n\n\n\n\n\n\n\n");
	printf("      ***********    ************       ***************        ************       ***       **           *\n");
	printf("      *              *          *       **            **       *          *       ** *      **          ***\n");
	printf("      *              *          *       **            *        *          *       **  *     **         *   *\n");
	printf("      *              *          *       **************         *          *       **   *    **        *     *\n");
	printf("      *              *          *       **            **       *          *       **    *   **       *********\n");
	printf("      *              *          *       **             **      *          *       **     *  **      *         *\n");
	printf("      ***********    ************       **              **     ************       **       ***     *           *\n\n");


	printf("                  ***************       ***************              *          *                *   \n");
	printf("                  *             *       **            **            ***         * *            * *    \n");
	printf("                  *                     **            *            *   *        *  *          *  *     \n");
	printf("                  *      ********       **************            *     *       *   *        *   *      \n");
	printf("                  *      *      *       **            **         *********      *    *      *    *       \n");
	printf("                  *             *       **             **       *         *     *     *    *     *        \n");
	printf("                  ***************       **              **     *           *    *       **       *         \n\n");

	printf(ANSI_COLOR_YELLOW" By Mahdi Ghasemi");
	k = time(NULL);
	printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t\t  Exact Time :  %s\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_CYAN"         ************************************** Welcome To Corona Gram *************************************\n\n");

	printf(ANSI_COLOR_GREEN"   1. login to the acount\n\n");

	printf("   2. Create a new acount\n\n");

	printf("   3. Reset password             \n\n");
	printf(ANSI_COLOR_MAGNETA" Enter the number or the text to go to each part\n\n");
	printf(ANSI_COLOR_GREEN"   input :");



	char menu[50];

	fgets(menu, 50, stdin);
	menu[strlen(menu) - 1] = '\0';


	if (strcmp(menu, "1") == 0 || strcmp(menu, "login to the acount") == 0)
		log_in();



	if (strcmp(menu, "3") == 0 || strcmp(menu, "Reset password") == 0) {
		forget_password();
	}



	if (strcmp(menu, "2") == 0 || strcmp(menu, "Create a new acount") == 0) {
		printf(ANSI_COLOR_CYAN" \n\n A. normal acount\n B. tejari acount\n\n");
		printf(ANSI_COLOR_MAGNETA" Enter the number or the text to go to each part\n\n");
		printf(ANSI_COLOR_CYAN" input :");
		char voroodi[50];
		fgets(voroodi, 50, stdin);
		voroodi[strlen(voroodi) - 1] = '\0';


		if (strcmp(voroodi, "normal acount") == 0 || strcmp(voroodi, "A") == 0)
		{
			create_normal();
		}

		if (strcmp(voroodi, "tejari acount") == 0 || strcmp(voroodi, "B") == 0) {
			create_tejari();
		}

	}



	printf(ANSI_COLOR_RED"\n You enter an undefined key ):\n\n");
	printf(ANSI_COLOR_RESET"  1. Home \n  2. Exit\n");
	printf("Enter a propriate number : ");
	fgets(homext, 5, stdin);
	homext[strlen(homext) - 1] = '\0';
	if (strcmp(homext, "1") == 0)
		graphic_name();
	else
		exit(0);


}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void log_in(void)
{
	pointernormal = fopen("normaluser.txt", "w");
	pointertejari = fopen("tejariuser.txt", "w");
	fwrite(&usern, sizeof(struct normal), countcreaten + 1, pointernormal);
	fwrite(&user, sizeof(struct tejari), countcreate + 1, pointertejari);
	fcloseall();



	system("cls");
	printf(ANSI_COLOR_CYAN"\n\n          **************************************** Log in to the acount ****************************************\n\n\n");
	printf(ANSI_COLOR_MAGNETA"\n\n\n$$$$$$$$$$$  Please Fill in the blanks  to go to your page ");
	k = time(NULL);
	printf(ANSI_COLOR_YELLOW" \t\t Exact Time :  %s\n\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_GREEN"  username  :  ");


	fgets(usernamevoroodi, 50, stdin);
	usernamevoroodi[strlen(usernamevoroodi) - 1] = '\0';

	printf("\n  Password :  ");
	password_to_star(password);
	int count = 0;


	for (count = 0; count <= num_mordegan + 1; count++) {
		if (strcmp(usernamevoroodi, mordegan[count].username) == 0 && strcmp(password, mordegan[count].password) == 0) {
			printf(ANSI_COLOR_RESET"\n\n Unfortunately You Are ");
			printf(ANSI_COLOR_RED"DEAD  \n\n\n");
			printf(ANSI_COLOR_YELLOW"\n\n  1. Home \n\n  2. Exit\n\n");
			printf(ANSI_COLOR_RESET" Enter a propriate number : ");
			fgets(homext, 5, stdin);
			homext[strlen(homext) - 1] = '\0';

			if (strcmp(homext, "1") == 0)
				graphic_name();
			else if (strcmp(homext, "2") == 0)
				exit(0);
		}


	}



	for (count = 0; count < countcreaten + 4; count++)
		if (strcmp(usernamevoroodi, usern[count].username) == 0 && strcmp(password, usern[count].password) == 0)//user1 normal 

			menu_u1nrml(count);


	for (count = 0; count < countcreate + 4; count++)
		if (strcmp(usernamevoroodi, user[count].username) == 0 && strcmp(password, user[count].password) == 0)//user1 tejari

			menu_u1tjr(count);


	if (strcmp(usernamevoroodi, adminn.username) == 0 && strcmp(password, adminn.password) == 0)//adminnnnnnnnnnnnnnnnnnn 

		menu_admin();



	printf(ANSI_COLOR_RED"\n\n  Your password or Your username is wrong ):\n\n");
	printf(ANSI_COLOR_YELLOW"\n  1. Forget password ?  Now Reset it easilly : )\n\n  2. Back to login page  \n\n  3. Home \n\n  4. Exit\n\n");
	printf(ANSI_COLOR_RESET" Enter a propriate number : ");
	fgets(homext, 5, stdin);
	homext[strlen(homext) - 1] = '\0';
	if (strcmp(homext, "1") == 0)
		forget_password();
	if (strcmp(homext, "2") == 0)
		log_in();
	if (strcmp(homext, "3") == 0)
		graphic_name();
	else if (strcmp(homext, "4") == 0)
		exit(0);

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void create_normal(void) {

	system("cls");


	printf(ANSI_COLOR_CYAN"\n\n       **************************************** Create Normal Acount ****************************************\n\n\n\n\n");
	printf(ANSI_COLOR_MAGNETA"***********Please fill in the blanks ");
	k = time(NULL);
	printf(ANSI_COLOR_YELLOW"\t\t\t\t\t    Exact Time :  %s\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_GREEN"\n\n\n  Name (mandatory) :  ");

	fgets(usern[countcreaten].name, 50, stdin);


	while (usern[countcreaten].name[0] == '\n') {



		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your Name Again  : ");
		fgets(usern[countcreaten].name, 50, stdin);


	}

	usern[countcreaten].name[strlen(usern[countcreaten].name) - 1] = '\0';

	printf("\n  Family name (mandatory) :  ");
	fgets(usern[countcreaten].familyname, 50, stdin);
	while (usern[countcreaten].familyname[0] == '\n') {




		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your Family name Again  : ");
		fgets(usern[countcreaten].familyname, 50, stdin);

	}

	usern[countcreaten].familyname[strlen(usern[countcreaten].familyname) - 1] = '\0';

	printf("\n  National Code (mandatory) :  ");
	fgets(usern[countcreaten].nationalcode, 50, stdin);
	while (usern[countcreaten].nationalcode[0] == '\n') {




		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your National Code Again  : ");
		fgets(usern[countcreaten].nationalcode, 50, stdin);

	}
	usern[countcreaten].nationalcode[strlen(usern[countcreaten].nationalcode) - 1] = '\0';

	printf("\n  Username (mandatory) :  ");
	fflush(stdin); fgets(usern[countcreaten].username, 50, stdin);

	while (usern[countcreaten].username[0] == '\n') {




		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your username Again  : ");
		fgets(usern[countcreaten].username, 50, stdin);


	}
	usern[countcreaten].username[strlen(usern[countcreaten].username) - 1] = '\0';




	printf("\n  Password  (mandatory) :  ");

	password_to_star(usern[countcreaten].password);

	printf("\n\n  Reapet your  password  (mandatory) :  ");

	while (1) {

		password_to_star(usern[countcreaten].tkrrpassword);
		if (strcmp(usern[countcreaten].tkrrpassword, usern[countcreaten].password) == 0)
			break;
		else if (usern[countcreaten].tkrrpassword[0] == '\n') {
			printf(ANSI_COLOR_RED" \n YOU should fill in the blank \n ");
			printf(ANSI_COLOR_GREEN"    Enter Your Password Again  : ");
			password_to_star(usern[countcreaten].tkrrpassword);
		}


		else {
			printf(ANSI_COLOR_RED"\n  Password and its reapitition must be same\n ");
			printf(ANSI_COLOR_GREEN"   So Reapeat your password  Again  : ");
			password_to_star(usern[countcreaten].tkrrpassword);
		}
	}




	printf("\n\n  Email Adress (mandatory)  ");
	fgets(usern[countcreaten].email_adress, 50, stdin);


	while (usern[countcreaten].email_adress[0] == '\n') {



		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your Email Adress Again  : ");
		fgets(usern[countcreaten].email_adress, 50, stdin);

	}
	usern[countcreaten].email_adress[strlen(usern[countcreaten].email_adress) - 1] = '\0';


	printf("\n  Blood type (optional)   :  ");//ekhtiari
	fgets(usern[countcreaten].blood_type, 50, stdin);
	usern[countcreaten].blood_type[strlen(usern[countcreaten].blood_type) - 1] = '\0';


	printf("\n  Age :  ");//ekhtiari
	fgets(usern[countcreaten].age, 50, stdin);
	usern[countcreaten].age[strlen(usern[countcreaten].age) - 1] = '\0';


	printf("\n  Height (optional)   :  ");//ekhtiari
	fgets(usern[countcreaten].hight, 50, stdin);
	usern[countcreaten].hight[strlen(usern[countcreaten].hight) - 1] = '\0';

	printf("\n  Weight (optional)   :  ");//ekhtiari
	fgets(usern[countcreaten].weight, 50, stdin);
	usern[countcreaten].weight[strlen(usern[countcreaten].weight) - 1] = '\0';

	for (i = 0; i < countcreaten; i++) {
		if (strcmp(usern[countcreaten].username, usern[i].username) == 0) {
			printf(ANSI_COLOR_RED"\n  Unfortunetly Your username has used before\n\n");
			printf(ANSI_COLOR_RESET"  So Please Enter an other username");
			printf("\n    Username (mandatory) :  ");
			fflush(stdin); fgets(usern[countcreaten].username, 50, stdin);

			while (usern[countcreaten].username[0] == '\n') {

				printf(ANSI_COLOR_RED"\n  YOU should fill in the blank \n ");
				printf(ANSI_COLOR_GREEN"    Enter Your username Again  : ");
				fgets(usern[countcreaten].username, 50, stdin);

			}
			usern[countcreaten].username[strlen(usern[countcreaten].username) - 1] = '\0';
			i = 0;
		}



	}
	for (i = 0; i < countcreaten; i++) {
		if (strcmp(usern[countcreaten].nationalcode, usern[i].nationalcode) == 0) {
			usern[countcreaten] = usern[countcreaten + 1];
			printf(ANSI_COLOR_RED"\n  You have an acount with this nationalcode\n");
			printf(ANSI_COLOR_YELLOW"\n  1. login with  your last acount  \n\n  2. Home \n\n  3. Exit\n\n");
			printf(ANSI_COLOR_RESET" Enter a propriate number : ");
			fgets(homext, 5, stdin);
			homext[strlen(homext) - 1] = '\0';
			if (strcmp(homext, "1") == 0)
				log_in();
			if (strcmp(homext, "2") == 0)
				graphic_name();
			else if (strcmp(homext, "3") == 0)
				exit(0);
		}


	}


	usern[countcreaten].codesalamat = 1;

	countcreaten++;

	pointernormal = fopen("normaluser.txt", "w");
	pointercounter = fopen("counter.txt", "w");


	fprintf(pointercounter, "%d %d %d %d", countcreaten, countcreate, num_mordegan, num_hospital);
	fwrite(&usern, sizeof(struct normal), countcreaten + 1, pointernormal);
	fcloseall();

	graphic_name();


}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void create_tejari(void) {

	system("cls");
	printf(ANSI_COLOR_CYAN"\n\n       ****************************************Create Tejari Acount****************************************\n\n\n\n\n");
	printf(ANSI_COLOR_MAGNETA"***********Please fill in the blanks ");
	k = time(NULL);
	printf(ANSI_COLOR_YELLOW"\t\t\t\t\t    Exact Time :  %s\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_GREEN"\n\n\n  Name (mandatory) :  ");
	fgets(user[countcreate].name, 50, stdin);
	while (user[countcreate].name[0] == '\n') {


		user[countcreate].name[strlen(user[countcreate].name) - 1] = '\0';

		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your Name Again  : ");
		fgets(user[countcreate].name, 50, stdin);
	}

	user[countcreate].name[strlen(user[countcreate].name) - 1] = '\0';
	printf("\n  Family name (mandatory) :  ");
	fgets(user[countcreate].familyname, 50, stdin);

	while (user[countcreate].familyname[0] == '\n') {




		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your Familyname Name Again  : ");
		fgets(user[countcreate].familyname, 50, stdin);


	}

	user[countcreate].familyname[strlen(user[countcreate].familyname) - 1] = '\0';
	printf("\n  Nationalcode  (mandatory) :  ");
	fgets(user[countcreate].nationalcode, 50, stdin);

	while (user[countcreate].nationalcode[0] == '\n') {




		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your National Code Again  : ");
		(fgets(user[countcreate].nationalcode, 50, stdin));

	}

	user[countcreate].nationalcode[strlen(user[countcreate].nationalcode) - 1] = '\0';

	printf("\n  username  (mandatory) :  ");
	fgets(user[countcreate].username, 50, stdin);

	while (user[countcreate].username[0] == '\n') {





		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your  username Again  : ");
		fgets(user[countcreate].username, 50, stdin);


	}
	user[countcreate].username[strlen(user[countcreate].username) - 1] = '\0';

	printf("\n  Password  (mandatory) :  ");

	password_to_star(user[countcreate].password);

	printf("\n\n  Reapet your  password  (mandatory) :  ");

	while (1) {

		password_to_star(user[countcreate].tkrrpassword);
		if (strcmp(user[countcreate].tkrrpassword, user[countcreate].password) == 0)
			break;
		else if (user[countcreate].tkrrpassword[0] == '\n') {
			printf(ANSI_COLOR_RED" \n YOU should fill in the blank \n ");
			printf(ANSI_COLOR_GREEN"    Enter Your Password Again  : ");
			password_to_star(user[countcreate].tkrrpassword);
		}


		else {
			printf(ANSI_COLOR_RED"\n  Password and its reapitition must be same\n ");
			printf(ANSI_COLOR_GREEN"   So Reapeat your password  Again  : ");
			continue;
		}
	}


	printf("\n\n  Email adress  (mandatory) : ");
	fgets(user[countcreate].email_adress, 50, stdin);

	while (user[countcreate].email_adress[0] == '\n') {





		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your Email Again  : ");
		fgets(user[countcreate].email_adress, 50, stdin);

	}
	user[countcreate].email_adress[strlen(user[countcreate].email_adress) - 1] = '\0';

	printf("\n  Shop   (mandatory) :  ");
	fgets(user[countcreate].mahalekar, 50, stdin);


	while (user[countcreate].mahalekar[0] == '\n') {




		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your shop Again  : ");
		fgets(user[countcreate].mahalekar, 50, stdin);



	}
	user[countcreate].mahalekar[strlen(user[countcreate].mahalekar) - 1] = '\0';

	printf("\n  City :  ");
	fgets(user[countcreate].shahr, 50, stdin);

	while (user[countcreate].shahr[0] == '\n') {





		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your City Again  : ");
		fgets(user[countcreate].shahr, 50, stdin);

	}
	user[countcreate].shahr[strlen(user[countcreate].shahr) - 1] = '\0';

	printf("\n  Area  (mandatory) :  ");
	fgets(user[countcreate].mantaghe, 50, stdin);

	while (user[countcreate].mantaghe[0] == '\n') {





		printf(ANSI_COLOR_RED"  YOU should fill in the blank \n ");
		printf(ANSI_COLOR_GREEN"    Enter Your Area Again  : ");
		fgets(user[countcreate].mantaghe, 50, stdin);

	}
	for (i = 0; i < countcreate; i++) {
		if (strcmp(user[countcreate].username, user[i].username) == 0) {
			printf(ANSI_COLOR_RED"\n  Unfortunetly Your username has used before\n\n");
			printf(ANSI_COLOR_RESET"  So Please Enter an other username");
			printf("\n    Username (mandatory) :  ");
			fflush(stdin); fgets(user[countcreate].username, 50, stdin);

			while (user[countcreate].username[0] == '\n') {

				printf(ANSI_COLOR_RED"\n  YOU should fill in the blank \n ");
				printf(ANSI_COLOR_GREEN"    Enter Your username Again  : ");
				fgets(user[countcreate].username, 50, stdin);

			}
			user[countcreate].username[strlen(user[countcreate].username) - 1] = '\0';
			i = -1;
		}



	}
	for (i = 0; i < countcreate; i++) {
		if (strcmp(user[countcreate].nationalcode, user[i].nationalcode) == 0) {
			user[countcreate] = user[countcreate + 1];
			printf(ANSI_COLOR_RED"\n  You have an acount with this nationalcode\n");
			printf(ANSI_COLOR_YELLOW"\n  1. login with  your last acount  \n\n  2. Home \n\n  3. Exit\n\n");
			printf(ANSI_COLOR_RESET" Enter a propriate number : ");
			fgets(homext, 5, stdin);
			homext[strlen(homext) - 1] = '\0';
			if (strcmp(homext, "1") == 0)
				log_in();
			if (strcmp(homext, "2") == 0)
				graphic_name();
			else if (strcmp(homext, "3") == 0)
				exit(0);
		}


	}
	user[countcreate].mantaghe[strlen(user[countcreate].mantaghe) - 1] = '\0';
	strcpy(user[countcreate].vazeiat, "Red");

	countcreate++;

	pointertejari = fopen("tejariuser.txt", "w");
	pointercounter = fopen("counter.txt", "w");

	fprintf(pointercounter, "%d %d %d %d", countcreaten, countcreate, num_mordegan, num_hospital);
	fwrite(&user, sizeof(struct tejari), countcreate + 1, pointertejari);
	fcloseall();
	graphic_name();


}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void forget_password(void)
{
	system("cls");
	int count;
	printf(ANSI_COLOR_CYAN"\n\n          **************************************** Reset Password ****************************************\n\n\n");
	printf(ANSI_COLOR_MAGNETA"\n\n$$$$$$$$$$$  Please fill in the blanks to Reset Your Password");
	k = time(NULL);
	printf(ANSI_COLOR_YELLOW"\t\t    Exact Time :  %s\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_GREEN"\n\n  username  :  ");


	fgets(usernamefrgt, 50, stdin);

	usernamefrgt[strlen(usernamefrgt) - 1] = '\0';
	printf("\n  Email Adress  :  ");


	fgets(emailfrgt, 50, stdin);
	emailfrgt[strlen(emailfrgt) - 1] = '\0';

	printf("\n  National Code  :  ");


	fgets(kodemelifrgt, 50, stdin);

	kodemelifrgt[strlen(kodemelifrgt) - 1] = '\0';

	for (count = 0; count < countcreaten; count++) {
		if (strcmp(usernamefrgt, usern[count].username) == 0 && strcmp(kodemelifrgt, usern[count].nationalcode) == 0 && strcmp(emailfrgt, usern[count].email_adress) == 0) {//user 2 normal
			printf(ANSI_COLOR_YELLOW"\n\n  Your information conformed sucssesfully\n\n  So now you can enter your new password\n\n");
			printf(ANSI_COLOR_RESET"  Enter your new password : ");
			password_to_star(usern[countcreaten].password);

			printf(ANSI_COLOR_RESET"  Repeat your new password : ");
			password_to_star(usern[countcreaten].tkrrpassword);
			while (1) {
				if (strcmp(usern[countcreaten].tkrrpassword, usern[countcreaten].password) == 0)
					break;
				else if (usern[countcreaten].tkrrpassword[0] == '\n') {
					printf(ANSI_COLOR_RED" \n YOU should fill in the blank \n ");
					printf(ANSI_COLOR_GREEN"    Enter Your Password Again  : ");
					password_to_star(usern[countcreaten].tkrrpassword);
				}

				else {
					printf(ANSI_COLOR_RED"\n  Password and its reapitition must be same\n ");
					printf(ANSI_COLOR_GREEN"   So Reapeat your password  Again  : ");
					password_to_star(usern[countcreaten].tkrrpassword);
				}
			}
			graphic_name();
		}
	}

	for (count = 0; count < countcreate; count++)
		if (strcmp(usernamefrgt, user[count].username) == 0 && strcmp(kodemelifrgt, user[count].nationalcode) == 0 && strcmp(emailfrgt, user[count].email_adress) == 0) {//user 1 tejari
			printf(ANSI_COLOR_YELLOW"\n\n  Your information conformed sucssesfully\n\n  So now you can enter your new password\n\n");
			printf(ANSI_COLOR_RESET"  Enter your new password : ");
			password_to_star(user[countcreate].password);

			printf(ANSI_COLOR_RESET"  Repeat your new password : ");
			password_to_star(user[countcreate].tkrrpassword);
			while (1) {
				if (strcmp(user[countcreate].tkrrpassword, user[countcreate].password) == 0)
					break;
				else if (user[countcreate].tkrrpassword[0] == '\n') {
					printf(ANSI_COLOR_RED" \n YOU should fill in the blank \n ");
					printf(ANSI_COLOR_GREEN"    Enter Your Password Again  : ");
					password_to_star(user[countcreate].tkrrpassword);
				}

				else {
					printf(ANSI_COLOR_RED"\n  Password and its reapitition must be same\n ");
					printf(ANSI_COLOR_GREEN"   So Reapeat your password  Again  : ");
					password_to_star(user[countcreate].tkrrpassword);
				}
			}
			graphic_name();
		}

		else if (strcmp(usernamefrgt, adminn.username) == 0 && strcmp(kodemelifrgt, adminn.national_code) == 0 && strcmp(emailfrgt, adminn.email) == 0) {//adminnn
			printf(ANSI_COLOR_YELLOW"\n\n  Your information conformed sucssesfully\n\n  So now you can enter your new password\n\n");
			printf(ANSI_COLOR_RESET"  Enter your new password : ");
			password_to_star(adminn.password);

			printf(ANSI_COLOR_RESET"  Repeat your new password : ");
			char b[20];
			password_to_star(b);
			while (1) {
				if (strcmp(b, adminn.password) == 0)
					break;
				else if (b[0] == '\n') {
					printf(ANSI_COLOR_RED" \n YOU should fill in the blank \n ");
					printf(ANSI_COLOR_GREEN"    Enter Your Password Again  : ");
					password_to_star(b);
				}

				else {
					printf(ANSI_COLOR_RED"\n  Password and its reapitition must be same\n ");
					printf(ANSI_COLOR_GREEN"   So Reapeat your password  Again  : ");
					password_to_star(b);
				}
			}
			graphic_name();

		}

		else {
			printf(ANSI_COLOR_RED"\n\n  one of your information is inccredable\n");
			printf(ANSI_COLOR_YELLOW"\n  1. Load Reset Password Page Again \n\n  2. Home \n\n  3. Exit\n\n");
			printf(ANSI_COLOR_RESET"  Enter a propriate number : ");
			fgets(homext, 5, stdin);
			homext[strlen(homext) - 1] = '\0';
			if (strcmp(homext, "1") == 0)
				forget_password();
			if (strcmp(homext, "2") == 0)
				graphic_name();
			else if (strcmp(homext, "3") == 0)
				exit(0);
		}



}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void health_situation(int id) {

	system("cls");
	int sum = 0, x = 0;
	char voroodi[50];
	printf(ANSI_COLOR_CYAN"\n\n         *********************************** Health Situation *************************************\n\n\n");
	printf(ANSI_COLOR_RED"\n\n $$$$$$$$$$$$  Hi  %s", usern[id].name);
	k = time(NULL);
	printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t\t    Exact Time :  %s\n\n\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_MAGNETA"********** Please answer the following questions in order signs you have with yes or no \n\n\n\n");




	while (1) {
		printf(ANSI_COLOR_GREEN"\n  Dry coughts in Large number ? : ");
		fgets(voroodi, 30, stdin);
		voroodi[strlen(voroodi) - 1] = '\0';
		if (strcmp(voroodi, "yes") == 0)
			sum += 30;
		else if (strcmp(voroodi, "no") != 0) {
			printf(ANSI_COLOR_RED"    Your input is undefined\n ");
			printf(ANSI_COLOR_RESET"      So Enter it again\n ");
			continue;
		}
		break;
	}
	while (1) {
		printf(ANSI_COLOR_GREEN"\n  Fever above  37 daragees ? : ");
		fgets(voroodi, 30, stdin);
		voroodi[strlen(voroodi) - 1] = '\0';
		if (strcmp(voroodi, "yes") == 0)
			sum += 20;
		else if (strcmp(voroodi, "no") != 0) {
			printf(ANSI_COLOR_RED"    Your input is undefined\n ");
			printf(ANSI_COLOR_RESET"      So Enter it again\n ");
			continue;
		}
		break;
	}
	while (1) {
		printf(ANSI_COLOR_GREEN"\n  Shortness of breath ? : ");
		fgets(voroodi, 30, stdin);
		voroodi[strlen(voroodi) - 1] = '\0';
		if (strcmp(voroodi, "yes") == 0)
			sum += 20;
		else if (strcmp(voroodi, "no") != 0) {
			printf(ANSI_COLOR_RED"    Your input is undefined\n ");
			printf(ANSI_COLOR_RESET"      So Enter it again\n ");
			continue;
		}
		break;
	}
	while (1) {
		printf(ANSI_COLOR_GREEN"\n  Pain and contusion ? : ");
		fgets(voroodi, 30, stdin);
		voroodi[strlen(voroodi) - 1] = '\0';
		if (strcmp(voroodi, "yes") == 0)
			sum += 15;
		else if (strcmp(voroodi, "no") != 0) {
			printf(ANSI_COLOR_RED"    Your input is undefined\n ");
			printf(ANSI_COLOR_RESET"      So Enter it again\n ");
			continue;
		}
		break;
	}
	while (1) {
		printf(ANSI_COLOR_GREEN"\n  Sore-throat ?  : ");
		fgets(voroodi, 30, stdin);
		voroodi[strlen(voroodi) - 1] = '\0';
		if (strcmp(voroodi, "yes") == 0)
			sum += 15;
		else if (strcmp(voroodi, "no") != 0) {
			printf(ANSI_COLOR_RED"    Your input is undefined\n ");
			printf(ANSI_COLOR_RESET"      So Enter it again\n ");
			continue;
		}
		break;
	}



	if (sum <= 15 && sum >= 0) {
		printf(ANSI_COLOR_RESET"\n\n  Your Health Code is 1\n\n   So you are salem");

		helper = 1;


	}

	else if (sum <= 50 && sum > 15) {
		printf("\n\n  Your Health code is 2\n\n   So you are mashkook");

		helper = 2;

	}



	else if (sum <= 75 && sum > 50) {
		helper = 3;


		printf(ANSI_COLOR_RED"\n\n  Your Health code is 3 \n\n   So you are Khatary !!", usern[id].codesalamat);
	}


	if (sum <= 100 && sum > 75) {
		printf(ANSI_COLOR_RED"\n\n  Your Health code is 4\n\n   We do not have any doubt in your illness  !!!  ):  ");
		helper = 4;
	}

	if ((usern[id].codesalamat > helper) && (usern[id].codesalamat) != 0) {

	}
	else {

		usern[id].codesalamat = helper;
		usern[id].onlinesalamat[usern[id].tsabtvazeiat] = usern[id].codesalamat;
		t = time(NULL);
		timesaving1[id] = t;
		struct tm* locall = localtime(&t);
		sprintf(usern[id].timesabtevazeiat[usern[id].tsabtvazeiat], "%s", asctime(locall));



		pointernormal = fopen("normaluser.txt", "w");
		pointertejari = fopen("tejariuser.txt", "w");
		pointertime1 = fopen("time_saving.txt", "w");

		usern[id].tsabtvazeiat++;
		for (int j = 0; j < countcreaten; j++) {
			fprintf(pointertime1, "%d\n", timesaving1[j]);
		}





		fwrite(&usern, sizeof(struct normal), countcreaten + 1, pointernormal);
		fwrite(&user, sizeof(struct tejari), countcreate + 1, pointertejari);
		fcloseall();
	}

	for (i = 0; i < countcreaten; i++) {
		time_t q3 = time(NULL);
		if ((q3 - timesaving2[id][i]) < 60 * 60 * 24 * 7) {
			if (usern[id].codesalamat > 2 && usern[id].codesalamat > usern[i].codesalamat) {
				usern[i].codesalamat = usern[id].codesalamat - 1;
				timesaving1[i] = q3;
			}

			if (usern[i].codesalamat > 2 && usern[i].codesalamat > usern[id].codesalamat) {
				usern[id].codesalamat = usern[i].codesalamat - 1;
				timesaving1[id] = q3;
			}


		}
	}



	printf(ANSI_COLOR_YELLOW"\n\n  1. Menu\n  2. Health Test\n  3. Lock\n  4. Exit");
	printf(ANSI_COLOR_MAGNETA"\n\n  Enter the propriate number to go to each part \n\n ");
	printf(ANSI_COLOR_GREEN"");
	fgets(homext, 50, stdin);
	homext[strlen(homext) - 1] = '\0';

	if (strcmp(homext, "1") == 0)
		menu_u1nrml(id);
	if (strcmp(homext, "2") == 0)
		health_situation(id);
	if (strcmp(homext, "3") == 0)
		graphic_name();
	if (strcmp(homext, "4") == 0)

		exit(0);

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void menu_u1nrml(int id)
{

	system("cls");
	char a[50];
	pointernormal = fopen("normaluser.txt", "w");
	pointertejari = fopen("tejariuser.txt", "w");

	fwrite(&usern, sizeof(struct normal), countcreaten + 1, pointernormal);
	fwrite(&user, sizeof(struct tejari), countcreate + 1, pointertejari);
	fcloseall();

	printf(ANSI_COLOR_CYAN"\n\n      ******************************************** MENU NORMAL USER ********************************************\n\n\n\n\n");
	printf(ANSI_COLOR_RED" $$$$$$$$$$  Hi  %s", usern[id].name);
	k = time(NULL);
	printf(ANSI_COLOR_RED"\t\t\t\t\t\t\t      Exact Time :  %s\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_YELLOW"\n\n\t\t1. Health situation                         2. Check History of Regisering Health Situation");
	printf("\n\n\t\t3. Register Recent Meetings                 4. Check the Recent Meetings     ");
	printf("\n\n\t\t5. Add places you have gone recently        6. Check History of Places you Have Gone Recently");
	printf("\n\n\t\t7. Check statistics of #Coronavirous        8. Check Hospitals in your Area");
	printf("\n\n\t\t9. Edit Profile \t\t\t    10. Lock ");
	printf("\n\n\t\t11. #Coronavirous learning \t\t    0. Exit \n\n");
	printf(ANSI_COLOR_MAGNETA"Enter the number or the text to go to each part\n\n");
	printf(ANSI_COLOR_GREEN"input : ");

	fgets(a, 50, stdin);
	a[strlen(a) - 1] = '\0';


	time_t n1 = time(NULL);
	if ((timesaving1[id] != 0) && ((n1 - timesaving1[id]) > 60 * 60 * 24 * 7)) {
		if (usern[id].codesalamat == 3) {
			usern[id].codesalamat = 2;
			timesaving1[id] = n1;

		}
		else if (usern[id].codesalamat == 2) {
			usern[id].codesalamat = 1;
		}

	}



	if (strcmp(a, "1") == 0 || strcmp(a, "health situation") == 0)
	{
		if (usern[id].codesalamat == 4) {
			printf(ANSI_COLOR_RED"\n You have #Coronavirous So we can not let you to test");
			homextmenu(id);
		}
		else
			health_situation(id);
	}
	if (strcmp(a, "2") == 0 || strcmp(a, "Check History of Regisering Health Situation") == 0)
	{

		int x = 0;
		printf(ANSI_COLOR_MAGNETA"\n\n\t\t\tHealth Code\t\tTime Registering\n\n");
		for (int i = 0; i < usern[id].tsabtvazeiat; i++) {



			printf(ANSI_COLOR_CYAN"\t\t\t%d\t\t", usern[id].onlinesalamat[i]);
			printf("%s\n", usern[id].timesabtevazeiat[i]);


		}

	}


	if (strcmp(a, "3") == 0 || strcmp(a, "Register Recent Meetings") == 0)
	{

		printf(ANSI_COLOR_CYAN"\n Enter the national code of people you have meet recrntly : ");
		fgets(x, 50, stdin);
		x[strlen(x) - 1] = '\0';
		for (int i = 0; i < countcreaten; i++) {
			if (strcmp(x, usern[i].nationalcode) == 0) {

				q = time(NULL);
				timesaving2[id][i] = q;
				struct tm* locall = localtime(&q);
				sprintf(usern[id].timemolaghat[usern[id].num_molaghat], "%s", asctime(locall));
				sprintf(usern[i].timemolaghat[usern[i].num_molaghat], "%s", asctime(locall));
				sprintf(usern[id].fardmolaghati[usern[id].num_molaghat], "%s", usern[i].name);
				sprintf(usern[i].fardmolaghati[usern[i].num_molaghat], "%s", usern[id].name);
				usern[id].code_molaghati[usern[id].num_molaghat] = usern[i].codesalamat;
				usern[i].code_molaghati[usern[i].num_molaghat] = usern[id].codesalamat;
				usern[id].num_molaghat++;
				usern[i].num_molaghat++;
				for (i = 0; i < countcreaten; i++) {
					time_t q3 = time(NULL);
					if ((q3 - timesaving2[id][i]) < 60 * 60 * 24 * 7) {
						if (usern[id].codesalamat > 2 && usern[id].codesalamat > usern[i].codesalamat) {
							usern[i].codesalamat = usern[id].codesalamat - 1;
							timesaving1[i] = q3;
						}

						if (usern[i].codesalamat > 2 && usern[i].codesalamat > usern[id].codesalamat) {
							usern[id].codesalamat = usern[i].codesalamat - 1;
							timesaving1[id] = q3;
						}


					}
				}



				printf(ANSI_COLOR_RESET"\n Your reqire registred sucssesfully\n  ");
				pointertime2 = fopen("time_saving2.txt", "w");



				for (int j = 0; j < countcreaten; j++) {
					for (int i = 0; i <= countcreaten; i++) {
						fprintf(pointertime2, "%d\n", timesaving2[j][i]);
					}
				}
				fclose(pointertime2);

				homextmenu(id);
			}
		}
		printf(ANSI_COLOR_RED"Your input was incridble");

	}


	if (strcmp(a, "4") == 0 || strcmp(a, "Check the Recent Meetings") == 0)
	{



		printf(ANSI_COLOR_MAGNETA"\n\n\t\tName of the meeted person\t\tCode of Meeted person\t\tTime Registering\n\n");
		for (int i = 0; i < countcreaten; i++) {
			if (usern[id].code_molaghati[i] == 0)
				continue;
			printf(ANSI_COLOR_CYAN"\t\t\t%s\t\t\t\t\t", usern[id].fardmolaghati[i]);
			printf("%d\t\t\t", usern[id].code_molaghati[i]);
			printf("%s\n\n", usern[id].timemolaghat[i]);
		}
		homextmenu(id);
	}



	if (strcmp(a, "5") == 0 || strcmp(a, "Add places you have gone recently") == 0)
	{

		printf("Enter The name of Places you have gone recently : ");
		fgets(x, 50, stdin);
		x[strlen(x) - 1] = '\0';
		for (int i = 0; i < countcreate; i++) {
			if (strcmp(x, user[i].mahalekar) == 0) {
				printf(ANSI_COLOR_RESET" your reqire registred sucssesfully\n  ");



				q2 = time(NULL);
				timesaving3[i][id] = q2;


				struct tm* abc = localtime(&q2);
				sprintf(usern[id].placetimemolaghat[usern[id].num_molaghat_place], "%s", asctime(abc));
				sprintf(usern[id].placemolaghati[usern[id].num_molaghat_place], "%s", user[i].mahalekar);
				sprintf(usern[id].vazeiate_molaghati[usern[id].num_molaghat_place], "%s", user[i].vazeiat);


				usern[id].num_molaghat_place++;
				pointertime3 = fopen("time_saving3.txt", "w");



				for (int j = 0; j < countcreaten; j++) {
					for (int i = 0; i <= usern[j].num_molaghat_place; i++) {
						fprintf(pointertime3, "%d\n", timesaving3[j][i]);
					}
				}
				fclose(pointertime3);




				if (strcmp(user[i].vazeiat, "Red") == 0) {
					printf("This place is already in red situation\n we want from you to enseraf az going there ");
					fgets(homext, 50, stdin);
					homext[strlen(homext) - 1] = '\0';
					if (strcmp(homext, "Enseraf") == 0)
						menu_u1nrml(id);
					if (strcmp(homext, "Edame") == 0)
						if (usern[id].codesalamat == 1)
							usern[id].codesalamat = 2;

				}
			}
		}

		printf("We dont have place with this name\n\n");
		homextmenu(id);
	}


	if (strcmp(a, "6") == 0 || strcmp(a, "Check History of Places you Have Gone Recently") == 0) {

		time_t q4 = time(NULL);


		printf(ANSI_COLOR_MAGNETA"\n\n\t\t\tName of the visited places\t\tvazeiate makan\t\tTime Registering\n\n");


		for (int i = 0; i < usern[id].num_molaghat_place; i++) {
			printf(ANSI_COLOR_CYAN"\t\t\t\t%s\t\t\t\t   ", usern[id].placemolaghati[i]);
			printf("%s\t\t\t", usern[id].vazeiate_molaghati);
			printf("%s\n", usern[id].placetimemolaghat[i]);
		}

		homextmenu(id);
	}

	if (strcmp(a, "7") == 0 || strcmp(a, "Check Statistics of #Coronavirous") == 0) {
		printf(ANSI_COLOR_GREEN"\t\t From a day ago\t\t\t\t\t\tFrom a year ago\n\n");
		printf(ANSI_COLOR_MAGNETA"\tName\t\tTime Registeringt\t\t\t\tName\t\tTime Registering\n\n");
		for (i = 0; i < countcreaten; i++) {

			if (usern[i].codesalamat == 4) {
				time_t e = time(NULL);
				if (e - timesaving1[i] < 60 * 60 * 24) {
					printf(ANSI_COLOR_CYAN"      %s\t\t", usern[i].name);
					printf("%s\n", usern[i].timesabtevazeiat[usern[i].tsabtvazeiat - 1]);
				}
				else if (e - timesaving1[i] < 60 * 60 * 24 * 7) {
					printf(ANSI_COLOR_CYAN"      \t\t\t\t\t\t\t\t\t%s\t\t", usern[i].name);
					printf("%s\n", usern[i].timesabtevazeiat[usern[i].tsabtvazeiat - 1]);

				}


			}
		}
		homextmenu(id);
	}


	if (strcmp(a, "8") == 0 || strcmp(a, "Check Hospitals in your Area") == 0)
	{
		printf("\n\nEnter Your City : ");
		fgets(grbj1, 30, stdin);
		grbj1[strlen(grbj1) - 1] = '\0';
		printf("\n\nEnter Your Area : ");
		fgets(grbj2, 30, stdin);
		grbj2[strlen(grbj2) - 1] = '\0';
		printf(ANSI_COLOR_MAGNETA"\t\t\t\tHospital name\n\n");
		for (i = 0; i < num_hospital; i++) {

			if (strcmp(grbj1, hospital[i].city) == 0 && strcmp(grbj2, hospital[i].area) == 0) {
				printf(ANSI_COLOR_CYAN"\t\t\t\t%s\n\n", hospital[i].name);
			}

		}

	}
	if (strcmp(a, "9") == 0 || strcmp(a, "Edit Profile") == 0)
		editu1nrml(id);

	else if (strcmp(a, "10") == 0 || strcmp(a, "lock") == 0)
		graphic_name();
	else if (strcmp(a, "11") == 0 || strcmp(a, "#Coronavirous learning") == 0) {
		coronavirouslearning();
		homextmenu(id);
	}

	pointernormal = fopen("normaluser.txt", "w");
	pointertejari = fopen("tejariuser.txt", "w");
	pointeradmin = fopen("adminuser.txt", "w");

	fwrite(&usern, sizeof(struct normal), countcreaten + 1, pointernormal);
	fwrite(&user, sizeof(struct tejari), countcreate + 1, pointertejari);

	fcloseall();

	if (strcmp(a, "0") == 0 || strcmp(a, "exit") == 0) {

		exit(0);
	}

	homextmenu(id);


}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void menu_u1tjr(int id)
{

	system("cls");
	pointernormal = fopen("normaluser.txt", "w");
	pointertejari = fopen("tejariuser.txt", "w");

	fwrite(&usern, sizeof(struct normal), countcreaten + 1, pointernormal);
	fwrite(&user, sizeof(struct tejari), countcreate + 1, pointertejari);
	fcloseall();

	char a[50];
	printf(ANSI_COLOR_CYAN"\n\n          **************************************** MENU Seller ****************************************\n\n\n");

	printf(ANSI_COLOR_RED"  $$$$$$$$$$$  Hi  %s", user[id].name);
	k = time(NULL);
	printf("\t\t\t\t\t\t    Exact Time :  %s\n\n\n\n", asctime(localtime(&k)));

	printf(ANSI_COLOR_YELLOW"\n\n\t\t1.  Checking place Situation (Red or White)\t\t2.  Reporting for Disinfection");

	printf("\n\n\t\t3.  Check the number of Patient users\t\t\t4.  Edit Profile");


	printf("\n\n\t\t5. Lock\t\t\t\t\t\t\t6. Exit ");
	printf(ANSI_COLOR_MAGNETA"\n\n\n\n Enter the number to go to each part\n");

	printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\t\t \n\ninput :");

	fgets(a, 50, stdin);
	a[strlen(a) - 1] = '\0';



	int x = 0;
	for (x = 0; x < countcreaten; x++) {
		for (i = 0; i < usern[x].num_molaghat_place; i++) {
			for (int j = 0; j < countcreate; j++)

			{
				time_t q3 = time(NULL);
				if (strcmp(usern[x].placemolaghati[i], user[id].mahalekar) == 0)
					if (usern[x].codesalamat == 4 && (q3 - timesaving3[id][i]) < (60 * 60 * 24 * 7))
						strcpy(user[id].mahalekar, "Red");

			}


		}
	}
	x = 0;

	if (strcmp(a, "1") == 0 || strcmp(a, "Checking place Situation (Red or White)") == 0)
	{

		if (strcmp(user[id].vazeiat, "Red") == 0)
			printf(ANSI_COLOR_RED"  Unfortunately  Your shop is in Red situation \n   So please disinfect as soon as possible then come again");
		else if (strcmp(user[id].vazeiat, "White") == 0)
			printf("Your marrt disinfect sucssesfully");
		homextmenutejari(id);
	}

	else if (strcmp(a, "2") == 0 || strcmp(a, "Reporting for Disinfection") == 0) {


		char ss[50];
		printf(ANSI_COLOR_RESET"\n  if you disinfect your mart enter  \"disinfect\"\n\n   input :  ");

		fgets(ss, 50, stdin);
		ss[strlen(ss) - 1] = '\0';



		if (strcmp(ss, "disinfect") == 0) {
			printf("\n\nYour Request registred");
			strcpy(user[id].vazeiat, "White");

		}
		homextmenutejari(id);
	}

	else if (strcmp(a, "3") == 0 || strcmp(a, "Check the number of Patient users") == 0)//nemayeshe afrade mobtala
	{
		int a = 0, b = 0, c = 0, d = 0;
		printf(ANSI_COLOR_CYAN"");

		int j;
		for (int i = 0; i < countcreaten; i++) {
			for (j = 0; j < usern[i].num_molaghat_place; j++) {
				if (strcmp(user[id].mahalekar, usern[i].placemolaghati[j]) == 0) {
					if (usern[i].codesalamat == 1) {
						a++;
					}
					if (usern[i].codesalamat == 2) {
						b++;
					}
					if (usern[i].codesalamat == 3) {
						c++;
					}
					if (usern[i].codesalamat == 4) {
						d++;
					}
				}

			}

		}
		printf("\t\t\t%d   user with Health Code 1\n\n\t\t\t%d   user with Health Code 2\n\n\t\t\t%d   user with Health Code 3\n\n\t\t\t%d   user with Health Code 4\n\n", a, b, c, d);

		homextmenutejari(id);
	}

	else if (strcmp(a, "4") == 0 || strcmp(a, "Edit Profile") == 0)
	{
		editu1tjr(id);
	}

	else if (strcmp(a, "5") == 0 || strcmp(a, "Lock") == 0)
	{
		graphic_name();
	}
	else if (strcmp(a, "6") == 0 || strcmp(a, "Exit") == 0) {
		exit(0);
	}





}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void menu_admin()
{
	time_t n1 = time(NULL);
	for (i = 0; i < countcreaten; i++) {
		if ((timesaving1[i] != 0) && ((n1 - timesaving1[i]) > 60 * 60 * 24 * 7)) {
			if (usern[i].codesalamat == 3) {
				usern[i].codesalamat = 2;
				timesaving1[i] = n1;

			}
			else if (usern[i].codesalamat == 2) {
				usern[i].codesalamat = 1;
			}

		}
	}

	system("cls");
	printf(ANSI_COLOR_CYAN"\n\n      ******************************************** MENU ADMIN ********************************************\n\n\n\n\n");

	printf(ANSI_COLOR_RED"$$$$$$  Hi  %s", adminn.username);
	k = time(NULL);
	printf("\t\t\t\t\t\t    Exact Time :  %s\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_YELLOW"\n\n\t\t\t1. Add Hospital                         2. Check statistics of #Coronavirous");
	printf("\n\n\t\t\t3. Add DEAD member                \t4. Add behbood yaftes");
	printf("\n\n\t\t\t5. Check all of users       \t\t6. Check DEAD members");
	printf("\n\n\t\t\t7. Check all of tejari users     \t8. Check all of the Hospitals");
	printf("\n\n\t\t\t9. Edit Profile \t\t\t10. Lock ");
	printf("\n\n\t\t\t\t\t\t0.   Exit \n\n");
	printf(ANSI_COLOR_MAGNETA"Enter the number or the text to go to each part\n\n");
	printf(ANSI_COLOR_GREEN"input : ");

	char a[50];

	fgets(a, 50, stdin);
	a[strlen(a) - 1] = '\0';

	if (strcmp(a, "1") == 0 || strcmp(a, "Add Hospital") == 0)
	{
		printf(ANSI_COLOR_GREEN"\n\n  Enter the Name of hospital : ");
		fgets(hospital[num_hospital].name, 50, stdin);
		hospital[num_hospital].name[strlen(hospital[num_hospital].name) - 1] = '\0';
		printf("\n\n  Enter the City of hospital : ");
		fgets(hospital[num_hospital].city, 50, stdin);
		hospital[num_hospital].city[strlen(hospital[num_hospital].city) - 1] = '\0';
		printf("\n\n  Enter the Area of hospital : ");
		fgets(hospital[num_hospital].area, 50, stdin);
		hospital[num_hospital].area[strlen(hospital[num_hospital].area) - 1] = '\0';
		num_hospital++;
		pointerhospital = fopen("hospital.txt", "w");
		pointercounter = fopen("counter.txt", "w");

		fwrite(&hospital, sizeof(struct Hospital), num_hospital, pointerhospital);
		fprintf(pointercounter, "%d %d %d %d", countcreaten, countcreate, num_mordegan, num_hospital);
		fcloseall();
		printf(ANSI_COLOR_RESET"\n\n  Hospital Added susccesfully\n\n");
		adminhomextmenu();

	}
	if (strcmp(a, "2") == 0 || strcmp(a, "Check statistics of #Coronavirous") == 0)
	{

		printf(ANSI_COLOR_MAGNETA"\t\t\t\t\tName\t\tTime Registering\n\n");
		for (i = 0; i < countcreaten; i++) {

			if (usern[i].onlinesalamat[usern[i].tsabtvazeiat - 1] == 4) {

				printf(ANSI_COLOR_CYAN"\t\t\t\t\t%s\t\t", usern[i].name);
				printf("%s\n", usern[i].timesabtevazeiat[usern[i].tsabtvazeiat - 1]);

			}
		}
		adminhomextmenu();
	}

	if (strcmp(a, "3") == 0 || strcmp(a, "Add DEAD member") == 0)
	{
		int j;
		printf("Enter The namtional code of the dead user\n input : ");
		char b[20];
		fgets(b, 50, stdin);
		b[strlen(b) - 1] = '\0';
		for (i = 0; i <= countcreaten; i++) {
			if (strcmp(b, usern[i].nationalcode) == 0) {
				printf(ANSI_COLOR_RESET"\n\n your reqire registred sucssesfully\n  ");
				strcpy(mordegan[num_mordegan].name, usern[i].name);
				strcpy(mordegan[num_mordegan].familyname, usern[i].familyname);
				strcpy(mordegan[num_mordegan].nationalcode, usern[i].nationalcode);
				strcpy(mordegan[num_mordegan].username, usern[i].username);
				strcpy(mordegan[num_mordegan].password, usern[i].password);
				for (j = i; j < countcreaten; j++) {
					usern[j] = usern[j + 1];
				}
				pointermorde = fopen("mordeusers.txt", "w");
				pointercounter = fopen("counter.txt", "w");
				countcreaten--;
				num_mordegan++;
				fprintf(pointercounter, "%d %d %d %d", countcreaten, countcreate, num_mordegan, num_hospital);
				fwrite(&mordegan, sizeof(struct mordegane_moteharek), num_mordegan, pointermorde);
				fcloseall();
			}


		}
		adminhomextmenu();
	}

	if (strcmp(a, "4") == 0 || strcmp(a, "Add behbood yaftes") == 0)
	{
		int j;
		printf("Enter The namtional code of the dead user\n input : ");
		char b[20];
		fgets(b, 50, stdin);
		b[strlen(b) - 1] = '\0';
		for (i = 0; i <= countcreaten; i++) {
			if (strcmp(b, usern[i].nationalcode) == 0) {
				usern[i].codesalamat = 2;
				printf("Your Require Registered Succesfully");
			}
		}
		adminhomextmenu();
	}
	if (strcmp(a, "5") == 0 || strcmp(a, "Check all of users") == 0)
	{

		printf("\t\t\tName\t\tFamily Name\t\tNational Code\t\tHealth Code\n\n");
		for (i = 0; i < countcreaten; i++) {
			printf(ANSI_COLOR_CYAN"\t\t\t\t%s\t\t%s\t\t%s\t\t%d\n\n", usern[i].name, usern[i].familyname, usern[i].nationalcode, usern[i].codesalamat);

		}
		adminhomextmenu();
	}
	if (strcmp(a, "6") == 0 || strcmp(a, "Check DEAD members") == 0)
	{
		printf(ANSI_COLOR_MAGNETA"\t\t\tname\t\tfamilyname\t\tnationalcode\n\n");
		for (i = 0; i < num_mordegan; i++) {
			printf(ANSI_COLOR_CYAN"\t\t\t %s\t\t  %s\t\t\t%s\n\n", mordegan[i].name, mordegan[i].familyname, mordegan[i].nationalcode);

		}
		adminhomextmenu();
	}
	if (strcmp(a, "7") == 0 || strcmp(a, "Check all of tejari users") == 0)
	{
		printf("\t\t\tName\t\tNational Code\t\tSituation\n\n");
		for (i = 0; i < countcreate; i++) {
			printf(ANSI_COLOR_CYAN"\t\t\t%s\t\t%s\t\t%s\n\n", user[i].mahalekar, user[i].nationalcode, user[i].vazeiat);
		}
		adminhomextmenu();
	}

	if (strcmp(a, "8") == 0 || strcmp(a, "Check all of the Hospitals") == 0)
	{
		printf(ANSI_COLOR_MAGNETA"\t\t\tname\t\tCity\t\tArea\n\n");
		for (i = 0; i < num_hospital; i++) {
			printf(ANSI_COLOR_CYAN"\t\t\t%s\t\t%s\t\t%s\n\n", hospital[i].name, hospital[i].city, hospital[i].area);


		}
		
		adminhomextmenu();
	}
	if (strcmp(a, "9") == 0 || strcmp(a, "Edit Profile") == 0)
	{
		system("cls");
		editadmin();
	}
	if (strcmp(a, "10") == 0 || strcmp(a, "lock") == 0)
	{
		system("cls");
		graphic_name();
	}

	else if (strcmp(a, "0") == 0 || strcmp(a, "Exit") == 0) {


		exit(0);
	}

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void editu1nrml(int id) {


	system("cls");
	printf(ANSI_COLOR_CYAN"\n\n         ****************************************EDIT PROFILE****************************************\n\n\n\n\n");

	printf(ANSI_COLOR_RED"  $$$$$$$$$  Hi  %s", usern[id].name);
	k = time(NULL);
	printf("\t\t\t\t\t\t    Exact Time :  %s\n\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_YELLOW"\t\t\t1.Name\t\t\t2.Family Name\t\t\t3.Email Adress \n\n\n");
	printf(" \t\t\t4.UserName\t\t5.Password\t\t\t6.National Code\n\n\n");
	printf(" \t\t\t7.Age\t\t\t8.Height\t\t\t9.weight         \n\n\n");
	printf("\t\t\t\t\t\t10.BACK       ");
	printf(ANSI_COLOR_MAGNETA"\n\n***********Please the number of each information to edit or sign out \n");
	char order[50] = "";


	while (strcmp(order, "10") != 0) {
		printf(ANSI_COLOR_GREEN"\n\n  input : ");
		fgets(order, 50, stdin);
		order[strlen(order) - 1] = '\0';


		if (strcmp(order, "1") == 0) {
			printf(ANSI_COLOR_GREEN"\n\n\n Edit name  :  ");
			
			fgets(usern[id].name, 50, stdin);
			usern[id].name[strlen(usern[id].name) - 1] = '\0';
		}

		else if (strcmp(order, "2") == 0) {
			printf("\n Edit Family name  :  ");
			fgets(usern[id].familyname, 50, stdin);
			usern[id].familyname[strlen(usern[id].familyname) - 1] = '\0';
		}
		else if (strcmp(order, "3") == 0) {
			printf("\n Edit Email Adress   ");
			fgets(usern[id].email_adress, 50, stdin);
			usern[id].email_adress[strlen(usern[id].email_adress) - 1] = '\0';
		}
		else if (strcmp(order, "4") == 0) {
			printf("\nEdit Username  :  ");
			fgets(usern[id].username, 50, stdin);
			usern[id].username[strlen(usern[id].username) - 1] = '\0';
		}



		else if (strcmp(order, "5") == 0) {
			printf("\nEdit Password  :  ");
			password_to_star(usern[id].password);
		}

		else if (strcmp(order, "6") == 0) {
			printf("\n Edit National Code :  ");
			fgets(usern[id].nationalcode, 50, stdin);
			usern[id].nationalcode[strlen(usern[id].nationalcode) - 1] = '\0';

		}
		




		else if (strcmp(order, "7") == 0) {
			printf("\nEdit Age :  ");

			fgets(usern[id].age, 50, stdin);

			usern[id].age[strlen(usern[id].age) - 1] = '\0';
		}
		else if (strcmp(order, "8") == 0) {
			printf("\nEdit Height    :  ");
			fgets(usern[id].hight, 50, stdin);
			usern[id].hight[strlen(usern[id].hight) - 1] = '\0';
		}

		else if (strcmp(order, "9") == 0) {
			printf("\nEdit Weight    :  ");
			fgets(usern[id].weight, 50, stdin);
			usern[id].weight[strlen(usern[id].weight) - 1] = '\0';
		}
		else
			printf(ANSI_COLOR_RED"your order was not ideintified \n  Please enter 1 to 9 to edit each one or enter 10 to back to the menu");
	}
	menu_u1nrml(id);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void editu1tjr(int id) {


	system("cls");
	printf(ANSI_COLOR_CYAN"\n\n         ****************************************EDIT PROFILE****************************************\n\n\n\n\n");

	printf(ANSI_COLOR_RED"  $$$$$$$$$  Hi  %s", user[id].name);
	k = time(NULL);
	printf("\t\t\t\t\t\t\t    Exact Time :  %s\n\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_YELLOW"\t\t\t1. Name\t\t\t2. Family Name\t\t3. Email Adress \n\n\n");
	printf("\t\t\t4. UserName\t\t5. Password\t\t6. National Code\n\n\n");
	printf("\t\t\t7.Work Place\t\t8. City\t\t\t9. Area        \n\n\n");
	printf("\t\t\t\t\t\t10.BACK       ");
	printf(ANSI_COLOR_MAGNETA"\n\n\n***********Please the number of each information to edit or sign out \n");
	char order[50] = "";


	while (strcmp(order, "10") != 0) {
		printf(ANSI_COLOR_GREEN"\n\nInput : ");
		fgets(order, 50, stdin);
		order[strlen(order) - 1] = '\0';


		if (strcmp(order, "1") == 0) {
			printf(ANSI_COLOR_GREEN"\n\n\n Edit Name  :  ");
			fgets(user[id].name, 50, stdin);
			user[id].name[strlen(user[id].name) - 1] = '\0';
		}

		else if (strcmp(order, "2") == 0) {
			printf("\n Edit Family name  :  ");
			fgets(user[id].familyname, 50, stdin);
			user[id].familyname[strlen(user[id].familyname) - 1] = '\0';
		}
		else if (strcmp(order, "3") == 0) {

			printf("\n Edit Email Adress   ");
			fgets(user[id].email_adress, 50, stdin);
			user[id].email_adress[strlen(user[id].email_adress) - 1] = '\0';
		}
		else if (strcmp(order, "4") == 0) {
			printf("\nEdit Username  :  ");
			fgets(user[id].username, 50, stdin);
			user[id].username[strlen(user[id].username) - 1] = '\0';
		}



		else if (strcmp(order, "5") == 0) {
			printf("\nEdit Password  :  ");
			password_to_star(user[id].password);
		}

		else if (strcmp(order, "6") == 0) {
			printf("\n Edit National Code :  ");
			fgets(user[id].nationalcode, 50, stdin);
			user[id].nationalcode[strlen(user[id].nationalcode) - 1] = '\0';

		}



		else if (strcmp(order, "7") == 0) {
			printf("\nEdit WorkPlace :  ");

			fgets(user[id].mahalekar, 50, stdin);

			user[id].mahalekar[strlen(user[id].mahalekar) - 1] = '\0';
		}
		else if (strcmp(order, "8") == 0) {
			printf("\nEdit City    :  ");

			fgets(user[id].shahr, 50, stdin);

			user[id].shahr[strlen(user[id].shahr) - 1] = '\0';
		}

		else if (strcmp(order, "9") == 0) {
			printf("\nEdit Area    :  ");


			fgets(user[id].mantaghe, 50, stdin);
			user[id].mantaghe[strlen(user[id].mantaghe) - 1] = '\0';
		}
		else
			printf(ANSI_COLOR_RED"your order was not ideintified \n  Please enter 1 to 9 to edit each one or enter 10 to back to the menu");


	}
	menu_u1tjr(id);


}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void editadmin() {

	system("cls");

	printf(ANSI_COLOR_CYAN"\n\n         ****************************************EDIT PROFILE****************************************\n\n\n\n\n");
	printf(ANSI_COLOR_RED"  $$$$$$$$$  Hi  %s", adminn.username);
	k = time(NULL);
	printf("\t\t\t\t\t\t    Exact Time :  %s\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_YELLOW"            \n\n\n");
	printf("\t\t\t\t1.UserName\t\t\t2.Password  \n\n\n");
	printf("\t\t\t\t3.National Code\t\t\t4.Email Adress  \n\n\n");
	printf("\t\t\t\t\t\t10.BACK       ");



	printf(ANSI_COLOR_MAGNETA"\n\n***********Please the number of each information to edit or sign out \n");
	char order[50] = "";


	while (strcmp(order, "10") != 0) {

		printf(ANSI_COLOR_GREEN"\n\nInput : ");
		fgets(order, 50, stdin);
		order[strlen(order) - 1] = '\0';

		int count;
		if (strcmp(order, "1") == 0) {
			printf(ANSI_COLOR_GREEN"\n\n\n Edit Name  :  ");
			fgets(adminn.username, 50, stdin);
			adminn.username[strlen(adminn.username) - 1] = '\0';
		}

		else if (strcmp(order, "2") == 0) {
			printf("\nEdit Password  :  ");
			password_to_star(adminn.password);
		}

		else if (strcmp(order, "3") == 0) {
			printf("\n Edit National Code :  ");
			fgets(adminn.national_code, 50, stdin);
			adminn.national_code[strlen(adminn.national_code) - 1] = '\0';

		}

		else if (strcmp(order, "4") == 0) {
			printf("\n Edit Email Adress   ");
			fgets(adminn.email, 50, stdin);
			adminn.email[strlen(adminn.email) - 1] = '\0';
		}



		else
			printf(ANSI_COLOR_RED"your order was not ideintified \n  Please enter 1 to 9 to edit each one or enter 10 to back to the menu");


	}
	pointeradmin = fopen("adminuser.txt", "w");

	fwrite(&adminn, sizeof(struct Admin), 1, pointeradmin);
	fcloseall();
	menu_admin();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void password_to_star(char str[50]) {
	int count;


	char ch1;
	for (count = 0; count < 50; count++)
	{
		ch1 = _getch();
		str[count] = ch1;

		if (str[0] == 13) {
			printf(ANSI_COLOR_RED" \n YOU should fill in the blank \n ");
			printf(ANSI_COLOR_GREEN"    Enter Your Password Again  : ");

			count--;
			continue;
		}

		else if (ch1 == 8 && count >= 1)
		{
			printf("\b \b");
			count -= 2;
			continue;
		}
		else if (ch1 != 13)
		{
			printf("*");
		}

		else if (ch1 == 13)
		{

			break;
		}


	}
	str[count] = '\0';
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void homextmenu(int id) {


	printf(ANSI_COLOR_YELLOW"\n\n  1. Menu \n\n  2.Home \n\n  3. Exit\n\n");
	printf(ANSI_COLOR_CYAN"Enter a propriate number : ");

	fgets(homext, 50, stdin);
	homext[strlen(homext) - 1] = '\0';

	if (strcmp(homext, "1") == 0)
		menu_u1nrml(id);
	else if (strcmp(homext, "2") == 0)
		graphic_name();
	else if (strcmp(homext, "3") == 0)
		exit(0);


}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void adminhomextmenu() {

	printf(ANSI_COLOR_YELLOW"\n\n  1. Menu \n\n  2. Lock\n\n  3. Exit\n\n");
	printf("   Enter a propriate number : ");
	fgets(homext, 50, stdin);
	homext[strlen(homext) - 1] = '\0';

	if (strcmp(homext, "1") == 0)
		menu_admin();
	else if (strcmp(homext, "2") == 0)
		graphic_name();
	else if (strcmp(homext, "3") == 0)
		exit(0);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void homextmenutejari(int id) {


	printf(ANSI_COLOR_YELLOW"\n\n  1. Menu \n\n  2.Home \n\n  3. Exit\n\n");
	printf(ANSI_COLOR_CYAN"Enter a propriate number : ");

	fgets(homext, 50, stdin);
	homext[strlen(homext) - 1] = '\0';

	if (strcmp(homext, "1") == 0)
		menu_u1tjr(id);
	else if (strcmp(homext, "2") == 0)
		graphic_name();
	else if (strcmp(homext, "3") == 0)
		exit(0);


}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void coronavirouslearning(void) {

	system("cls");
	printf(ANSI_COLOR_CYAN"\n\n       **************************************** #Corona Virous Learning ****************************************\n\n\n");

	k = time(NULL);
	printf(ANSI_COLOR_RED"  Exact Time :  %s\n\n", asctime(localtime(&k)));
	printf(ANSI_COLOR_RESET"");
	printf("\n\n****** 1.) Wash your hands repetadely");
	printf("\n\n****** 2.) Maintain Social Distance");
	printf("\n\n****** 3.) Observe respiratory hygiene");
	printf("\n\n****** 4.) Dont take your hands to your eyes ,nose and your mouse");
	printf("\n\n****** 5.) Dont go to unnecessary travels");
	printf("\n\n****** 6.) Try to Keep calm ");
	printf("\n\n****** 7.) Try to Awarrne of the News");
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
