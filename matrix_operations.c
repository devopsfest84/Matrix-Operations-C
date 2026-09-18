#include <stdio.h>
void addMatrix
	(int A[10][10], int B[10][10], int result[10][10], int r, int c)
	{
    	int i, j;

    	for (i = 0; i < r; i++)
    	{
        	for (j = 0; j < c; j++)
        	{
            	result[i][j] = A[i][j] + B[i][j];
        	}
    	}
	}
void subtractMatrix
	(int A[10][10], int B[10][10], int result[10][10], int r, int c)
	{
    	int i, j;

    	for (i = 0; i < r; i++)
    	{
        	for (j = 0; j < c; j++)
        	{
            	result[i][j] = A[i][j] - B[i][j];
        	}
    	}
	}
void multiplyMatrix
	(int A[10][10], int B[10][10], int result[10][10],int r1, int c1, int c2)
	{
    	int i, j, k;

    	for (i = 0; i < r1; i++)
    	{
        	for (j = 0; j < c2; j++)
        	{
            	result[i][j] = 0;

            	for (k = 0; k < c1; k++)
            	{
                	result[i][j] = result[i][j] + A[i][k] * B[k][j];
            	}
        	}
    	}
	}
	
void transposeMatrix
	(int A[10][10], int result[10][10], int r, int c)
	{
    	int i, j;

    	for (i = 0; i < c; i++)
    	{
        	for (j = 0; j < r; j++)
        	{
            	result[i][j] = A[j][i];
        	}
    	}
	}
	
int main()
{
    int matrixA[10][10];
    int matrixB[10][10];
    int result[10][10];

    int r1, c1;
    int r2, c2;

    int i, j;
    char op, choice;

    printf("------ MATRIX OPERATIONS ------\n\n");

    printf("Instructions:\n");
    printf("+  Addition\n");
    printf("-  Subtraction\n");
    printf("*  Multiplication\n");
    printf("T  Transpose of Matrix A\n");
    printf("q  Quit Matrix Operations\n\n");

    while (1)
    {
        /*
         * ENTER MATRIX A
         */

        printf("Enter number of rows for Matrix A: ");
        scanf("%d", &r1);

        printf("Enter number of columns for Matrix A: ");
        scanf("%d", &c1);

        if (r1 <= 0 || r1 > 10 || c1 <= 0 || c1 > 10)
        {
            printf("\nInvalid Matrix A size.\n\n");
            continue;
        }

        printf("\nEnter elements of Matrix A:\n");

        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                scanf("%d", &matrixA[i][j]);
            }
        }


        /*
         * ENTER MATRIX B
         */

        printf("\nEnter number of rows for Matrix B: ");
        scanf("%d", &r2);

        printf("Enter number of columns for Matrix B: ");
        scanf("%d", &c2);

        if (r2 <= 0 || r2 > 10 || c2 <= 0 || c2 > 10)
        {
            printf("\nInvalid Matrix B size.\n\n");
            continue;
        }

        printf("\nEnter elements of Matrix B:\n");

        for (i = 0; i < r2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                scanf("%d", &matrixB[i][j]);
            }
        }


        /*
         * OPERATION LOOP
         */

        while (1)
        {
            printf("\nEnter operator (+, -, *, T, q): ");
            scanf(" %c", &op);


            /*
             * QUIT
             */

            if (op == 'q' || op == 'Q')
            {
                printf("\nExiting Matrix Operations...\n");
                return 0;
            }


            /*
             * ADDITION
             */

   		if (op == '+')
		{
    		if (r1 != r2 || c1 != c2)
    		{
        		printf("\nAddition is not possible.\n");
        		printf("Both matrices must have the same size.\n");
        		continue;
   			 }
			addMatrix(matrixA, matrixB, result, r1, c1);

    		printf("\nResult of Addition:\n");

    		for (i = 0; i < r1; i++)
    		{
        		for (j = 0; j < c1; j++)
        		{
            		printf("%d\t", result[i][j]);
        		}

        	 printf("\n");
    		}
		}

            /*
             * SUBTRACTION
             */

		else if (op == '-')
		{
    		if (r1 != r2 || c1 != c2)
    		{
        		printf("\nSubtraction is not possible.\n");
        		printf("Both matrices must have the same size.\n");
        		continue;
    		}

    		subtractMatrix(matrixA, matrixB, result, r1, c1);

    		printf("\nResult of Subtraction:\n");

    		for (i = 0; i < r1; i++)
    		{
        		for (j = 0; j < c1; j++)
        		{
            		printf("%d\t", result[i][j]);
        		}
			printf("\n");
    		}
		}


            /*
             * MULTIPLICATION
             */

         else if (op == '*')
		{
    		 if (c1 != r2)
    		 {
        			printf("\nMultiplication is not possible.\n");
        			printf("Columns of Matrix A must equal");
        			printf(" rows of Matrix B.\n");
        			continue;
    		 }

    		 multiplyMatrix(matrixA, matrixB, result, r1, c1, c2);

    		 printf("\nResult of Multiplication:\n");

    		 for (i = 0; i < r1; i++)
    		 {
        			for (j = 0; j < c2; j++)
        			{
            		  printf("%d\t", result[i][j]);
        			}

        		 printf("\n");
    		}
		}

            /*
             * TRANSPOSE
             */

            else if (op == 'T' || op == 't')
			{
    			transposeMatrix(matrixA, result, r1, c1);

    			printf("\nTranspose of Matrix A:\n");

    			for (i = 0; i < c1; i++)
    			{
        			for (j = 0; j < r1; j++)
       			 	{
            			printf("%d\t", result[i][j]);
        			}

        			printf("\n");
    			}
			}

            /*
             * INVALID OPERATOR
             */

            else
            {
                printf("\nInvalid operator.\n");
                continue;
            }


            /*
             * WHAT NEXT?
             */

            printf("\n========================================\n");
            printf("What do you want to do next?\n");
            printf("========================================\n");

            printf("1. Continue with Result\n");
            printf("2. Perform another operation with A and B\n");
            printf("3. Enter New Matrices\n");
            printf("q. Quit\n");

            printf("\nEnter choice: ");
            scanf(" %c", &choice);


             /*
			 * 1. CONTINUE WITH RESULT
 			*/

			 if (choice == '1')
			 {
   				 /*
     			 * Result becomes Matrix A
     			 */

   				 if (op == '*')
   				 {
        		  c1 = c2;
   				 }
    			 else if (op == 'T' || op == 't')
  				  {
       				 int temp;
        			 temp = r1;
        			 r1 = c1;
        			 c1 = temp;
    			  }

    			 for (i = 0; i < r1; i++)
    			 {
        			for (j = 0; j < c1; j++)
       			    {
           		      matrixA[i][j] = result[i][j];
       				}
    			 }

    			 printf("\nResult is now Matrix A.\n");

    	      /*
    		  * Enter new Matrix B
     		  */

  			  printf("\nEnter number of rows for Matrix B: ");
    		  scanf("%d", &r2);

    		  printf("Enter number of columns for Matrix B: ");
    		  scanf("%d", &c2);
   			  if (r2 <= 0 || r2 > 10 || c2 <= 0 || c2 > 10)
    		     {
       		       printf("\nInvalid Matrix B size.\n");
       			   continue;
   				 }

    			 printf("\nEnter elements of Matrix B:\n");

    			 for (i = 0; i < r2; i++)
   				 {
        			for (j = 0; j < c2; j++)
        			{
           			 scanf("%d", &matrixB[i][j]);
        			}
    			 }

    			continue;
			 }

            /*
             * 2. SAME MATRIX A AND B
             */

            else if (choice == '2')
            {
                printf("\nMatrix A and Matrix B will remain the same.\n");

                continue;
            }


            /*
             * 3. NEW MATRICES
             */

            else if (choice == '3')
            {
                printf("\nStarting with new matrices...\n\n");

                break;
            }


            /*
             * QUIT
             */

            else if (choice == 'q' || choice == 'Q')
            {
                printf("\nExiting Matrix Operations...\n");
                return 0;
            }


            /*
             * INVALID CHOICE
             */

            else
            {
                printf("\nInvalid choice.\n");
            }
        }
    }

    return 0;
}
