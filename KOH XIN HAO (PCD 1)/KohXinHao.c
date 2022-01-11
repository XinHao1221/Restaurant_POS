#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
#define COMBO_A 10.00
#define COMBO_B 15.00
#define COMBO_C 18.00
#define COMBO_D 24.00
#define SST 0.1
#define UPGRADE_COMBO_A 2.00
#define UPGRADE_COMBO_B 3.00
#define UPGRADE_COMBO_C 5.00
#define UPGRADE_COMBO_D 6.00
// Define the constant value for each combo and the addition price to upgrade the combo

// Function declation for menu and customer's order and bills
void menu(void);
int order(void);

// Global declaration
char customer, upgradeCombo, choice;
double quantitySoldA, quantityUpgradeComboA, salesAmountA, quantitySoldB, quantityUpgradeComboB, salesAmountB;
double quantitySoldC, quantityUpgradeComboC, salesAmountC, quantitySoldD, quantityUpgradeComboD, salesAmountD; 
double totalA, totalB, totalC, totalD, totalA1, totalB1, totalC1, totalD1, ntotalA, ntotalB, ntotalC, ntotalD;
double ntotalA1, ntotalB1, ntotalC1, ntotalD1, total, cashTransaction, bankTransaction, totalQuantiySold, totalQuantityUpgradeCombo;
double quantity, comboCharges, sstCharges, totalPay, amountPaid, changeDue, sum, nSum, nsstCharges;
int a, paymentmethod, cardnumber;

a = 0;

// Main function in this program
void main(void)
{
	printf("                          ***  ****  ***     ***  ***    ***   \n");
	printf("                          *** ***     ***   ***   ***....***   \n");
	printf("                          ******        *****     **********   \n");
	printf("                          *** ***     ***   ***   ***    ***   \n");
	printf("                          ***  ****  ***     ***  ***    ***   \n");
	printf("                                KXH FAST FOOD SDN.BHD          \n");
	printf("                              NO.54, JALAN TEMBIKAI 17,        \n");
	printf("                                  TAMAN KOTA MASAI,            \n");
	printf("                                 81700 PASIR GUDANG,           \n");
	printf("                                       JOHOR.                  \n");
	printf("                              OFFICE TEL : +6073355886         \n");
	printf("                                     WELCOME ^-^               \n\n");

	// Display the menu and let customer order the food and let casheir choose whether have next customer or not
	do
	{
		menu();
		printf("\n Customer No: %d\n", ++a);
		int nSum = order();

		printf("\n\n");

		rewind(stdin);
		printf(" Have next customer (Y = yes, N = no)  : ");
		scanf("%c", &customer);
		rewind(stdin);

		printf("\n");

	} while (customer != 'n' && customer != 'N');

	// Calculate the total in the Daily Sales Report
	quantitySoldA = ntotalA / COMBO_A;
	quantitySoldB = ntotalB / COMBO_B;
	quantitySoldC = ntotalC / COMBO_C;
	quantitySoldD = ntotalD / COMBO_D;
	quantityUpgradeComboA = ntotalA1 / (COMBO_A + UPGRADE_COMBO_A);
	quantityUpgradeComboB = ntotalB1 / (COMBO_B + UPGRADE_COMBO_B);
	quantityUpgradeComboC = ntotalC1 / (COMBO_C + UPGRADE_COMBO_C);
	quantityUpgradeComboD = ntotalD1 / (COMBO_D + UPGRADE_COMBO_D);
	salesAmountA = ntotalA + ntotalA1;
	salesAmountB = ntotalB + ntotalB1;
	salesAmountC = ntotalC + ntotalC1;
	salesAmountD = ntotalD + ntotalD1;
	totalQuantiySold = quantitySoldA + quantitySoldB + quantitySoldC + quantitySoldD;
	totalQuantityUpgradeCombo = quantityUpgradeComboA + quantityUpgradeComboB + quantityUpgradeComboC + quantityUpgradeComboD;
	total = nSum + nsstCharges;

	// Print the Daily Sales Report
	printf(" =========================================================================================== \n\n");
	printf(" DAILY SALES REPORT \n\n");
	printf(" Total Number of Customer = %d \n\n", a);
	printf(" Combo        Quantity Sold    Quantity Upgrade Combo    Sales Amount\n");
	printf("   A                %-5.0lf                %-5.0lf             RM %6.2lf\n", quantitySoldA, quantityUpgradeComboA, salesAmountA);
	printf("   B                %-5.0lf                %-5.0lf             RM %6.2lf\n", quantitySoldB, quantityUpgradeComboB, salesAmountB);
	printf("   C                %-5.0lf                %-5.0lf             RM %6.2lf\n", quantitySoldC, quantityUpgradeComboC, salesAmountC);
	printf("   D                %-5.0lf                %-5.0lf             RM %6.2lf\n", quantitySoldD, quantityUpgradeComboD, salesAmountD);
	printf(" =====        =============     =====================     ===========\n");
	printf(" TOTALS             %-5.0lf                %-5.0lf             RM %6.2lf\n\n", totalQuantiySold, totalQuantityUpgradeCombo, nSum);
	printf("       TOTAL SST CHARGES                   =   RM %6.2lf\n", nsstCharges);
	printf("       TOTAL RM COLLECTED                  =   RM %6.2lf\n", cashTransaction);
	printf("       TOTAL DEBIT/CREDIT CARD TRANSACTION =   RM %6.2lf\n", bankTransaction);

	system("pause");

}

// Function definition to display menu
void menu(void)
{
	printf("                            MENU                                                           PRICE \n");
	printf("  COMBO A -> Chicken Burger + French Fries + CocaCola                                    RM 10.00 \n");
	printf("  COMBO B -> Beef Burger + French Fries + CocaCola                                       RM 15.00 \n");
	printf("  COMBO C -> Double Chicken Burger + Chicken Nuggets + CocaCola + Ice Cream              RM 18.00 \n");
	printf("  COMBO D -> Double Beef Burger + Onion Rings + Chicken Nuggets + CocaCola + Ice Cream   RM 24.00 \n");

}

// Function definition to let customer order the food and finally show the total amount to pay
int order(void)
{
	sum = 0;
	totalA = 0;
	totalB = 0;
	totalC = 0;
	totalD = 0;
	totalA1 = 0;
	totalB1 = 0;
	totalC1 = 0;
	totalD1 = 0;

	do {
		sum = sum + totalA + totalB + totalC + totalD + totalA1 + totalB1 + totalC1 + totalD1;
		printf(" Combo A, B, C, D (n = exit) : ");
		scanf("%c", &choice);
		printf(" Quantity (0 = exit)   : ");
		scanf(" %lf", &quantity);
		rewind(stdin);
		if (tolower(choice) == 'a')
		{
			// Ask customer whether want to upgrade the size of the combo
			printf(" Want to upgrade the sizes of your combo? (y = yes) : ");
			scanf(" %c", &upgradeCombo);
			rewind(stdin);
			if (tolower(upgradeCombo) == 'y')
			{
				totalA1 = quantity * (COMBO_A + UPGRADE_COMBO_A);
				printf("     COMBO A : (RM %.2lf + RM %.2lf) @ RM %.0lf = RM %8.2lf\n", COMBO_A, UPGRADE_COMBO_A, quantity, totalA1);
				totalB1 = 0;
				totalC1 = 0;
				totalD1 = 0;
				totalB = 0;
				totalC = 0;
				totalD = 0;
				ntotalA1 += totalA1;

			}
			else
			{
				totalA = COMBO_A * quantity;
				printf("     COMBO A : %.0lf  @  RM %.2lf = RM %8.2lf\n", quantity, COMBO_A, totalA);
				totalB = 0;
				totalC = 0;
				totalD = 0;
				totalA1 = 0;
				totalB1 = 0;
				totalC1 = 0;
				totalD1 = 0;
				ntotalA += totalA;
			}
		}
		else if (tolower(choice) == 'b')
		{
			printf(" Want to upgrade the sizes of your combo? (y = yes) : ");
			scanf(" %c", &upgradeCombo);
			rewind(stdin);
			if (tolower(upgradeCombo) == 'y')
			{
				totalB1 = quantity * (COMBO_B + UPGRADE_COMBO_B);
				printf("     COMBO B : (RM %.2lf + RM %.2lf) @ RM %.0lf = RM %8.2lf\n", COMBO_B, UPGRADE_COMBO_B, quantity, totalB1);
				totalA = 0;
				totalC = 0;
				totalD = 0;
				totalA1 = 0;
				totalC1 = 0;
				totalD1 = 0;
				ntotalB1 += totalB1;
			}
			else
			{
				totalB = COMBO_B * quantity;
				printf("     COMBO B : %.0lf  @  RM %.2lf = RM %8.2lf\n", quantity, COMBO_B, totalB);
				totalA = 0;
				totalC = 0;
				totalD = 0;
				totalA1 = 0;
				totalB1 = 0;
				totalC1 = 0;
				totalD1 = 0;
				ntotalB += totalB;
			}
		}
		else if (tolower(choice) == 'c')
		{
			printf(" Want to upgrade the sizes of your combo? (y = yes) : ");
			scanf(" %c", &upgradeCombo);
			rewind(stdin);
			if (tolower(upgradeCombo) == 'y')
			{
				totalC1 = quantity * (COMBO_C + UPGRADE_COMBO_C);
				printf("     COMBO C : (RM %.2lf + RM %.2lf) @ RM %.0lf = RM %8.2lf\n", COMBO_C, UPGRADE_COMBO_C, quantity, totalC1);
				totalA = 0;
				totalB = 0;
				totalD = 0;
				totalA1 = 0;
				totalB1 = 0;
				totalD1 = 0;
				ntotalC1 += totalC1;
			}
			else
			{
				totalC = COMBO_C * quantity;
				printf("     COMBO C : %.0lf  @  RM %.2lf = RM %8.2lf\n", quantity, COMBO_C, totalC);
				totalA = 0;
				totalB = 0;
				totalD = 0;
				totalA1 = 0;
				totalB1 = 0;
				totalC1 = 0;
				totalD1 = 0;
				ntotalC += totalC;
			}
		}
		else if (tolower(choice) == 'd')
		{
			printf(" Want to upgrade the sizes of your combo? (y = yes) : ");
			scanf(" %c", &upgradeCombo);
			rewind(stdin);
			if (tolower(upgradeCombo) == 'y')
			{
				totalD1 = quantity * (COMBO_D + UPGRADE_COMBO_D);
				printf("     COMBO D : (RM %.2lf + RM %.2lf) @ RM %.0lf = RM %8.2lf\n", COMBO_D, UPGRADE_COMBO_D, quantity, totalD1);
				totalA = 0;
				totalB = 0;
				totalC = 0;
				totalA1 = 0;
				totalB1 = 0;
				totalC1 = 0;
				ntotalD1 += totalD1;
			}
			else
			{
				totalD = COMBO_D * quantity;
				printf("     COMBO D : %.0lf  @  RM %.2lf = RM %8.2lf\n", quantity, COMBO_D, totalD);
				totalA = 0;
				totalB = 0;
				totalC = 0;
				totalA1 = 0;
				totalB1 = 0;
				totalC1 = 0;
				totalD1 = 0;
				ntotalD += totalD;
			}
		}
	} while (choice != 'n' && quantity != 0 && choice != 'N');

	sstCharges = sum * SST;
	totalPay = sum + sstCharges;


	// Let customer choose the payment method whether pay with cash or debit/credit card
	printf(" Payment Method (1 = cash, 2 = card) : ");
	scanf("%d", &paymentmethod);
	rewind(stdin);
	if (paymentmethod == 1)
	{
		printf("	    Combo Charges = RM %8.2lf\n", sum);
		printf("	    Add 10 %% SST  = RM %8.2lf\n", sstCharges);
		printf("	    TOTAL TO PAY  = RM %8.2lf\n", totalPay);
		printf("	    Amount paid   = RM   ");
		scanf("%lf", &amountPaid);
		changeDue = amountPaid - totalPay;
		printf("            Change Due    = RM %8.2lf\n\n", changeDue);
		printf(" THANK YOU, HAVE A NICE DAY AND COMMING AGAIN !!! ^-^");
		nSum += sum;
		nsstCharges += sstCharges;
		cashTransaction += totalPay;
	}
	else if (paymentmethod == 2)
	{
		printf("	    Combo Charges = RM %8.2lf\n", sum);
		printf("	    Add 10 %% SST  = RM %8.2lf\n", sstCharges);
		printf("	    TOTAL TO PAY  = RM %8.2lf\n", totalPay);
		printf(" PLease enter your credit/debit card number > ");
		scanf("%d", &cardnumber);
		printf(" Payment successful received ! \n");
		printf("\n THANK YOU, HAVE A NICE DAY AND COMMING AGAIN !!! ^-^");
		nSum += sum;
		nsstCharges += sstCharges;
		bankTransaction += totalPay;
	}

	return;

}