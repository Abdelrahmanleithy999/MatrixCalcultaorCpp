// ConsoleApplication13.cpp : Defines the entry point for the console application.
//Name :Abdelrahman Mahmoud Ehab Leithy 
// ID : 1809161 
// section : 4
// Junior mechatronics


#include<iostream> 
#include <cmath>
using namespace std ; 
double deter = 0.0;
int idol = 0;
double k, l, w, q;  //elements used in inverse of 2x2 matrix to save outputs from arrays 
void addition_matrix();
void subtraction_matrix();
void multiplication_matrix();
void determ_matrix();
void invers_matrix3();
void invers_matrix2();



int main()
{  
	int num_matrix ;
	cout << "please enter the number of matrices \n";
	cout << "if you want case (all operations ) enter any number except 2 or 1\n";
	cout << "if you want 2 matrices operation click (2) if you want 1 matrix operation click (1) \n";
	cin >> num_matrix; 


	if (num_matrix == 2) {
		cout << "please enter the number of operation 1 addition *** 2 subtraction *** 3 multiplication *** 4 Quit\n" ;
		int operation = 1;
		cin >> operation;
		switch (operation)
		{
		case 1: 
			addition_matrix(); 
			break;
		case 2 :
			subtraction_matrix();
			break;
		case 3 : 
			multiplication_matrix();
			break;
		case 4:
			cout << "Quit \n";
			break;
		default:
			cout << " Quit \n";
			break;
		}
	}
	else if (num_matrix == 1) {
		cout << "you are in operations of one matrix only \n ";
		cout << " you can make *** determinant operation (1) **** inverse operation (2)*** Quit (3) \n" ;
		int operation1;
		cin >> operation1;
		switch (operation1)
		{
		case 1 :
			determ_matrix();
			break;
		case 2 :
			int a, b; 
			back1 :
			cout << "you are in inverse matrix case \n";
			cout << "enter size of matrix 3x3 or 2x2 are allowed \n";
			cin >> a >> b;
			if (a == b && b == 3) {
				invers_matrix3(); 
				
			}
			else if (a == b && a == 2) {
				invers_matrix2();
			}
			else {
				goto back1;
			}
			break;
		case 3 :
			cout << "Quit \n";
			break;

		default:
			cout << "Quit case \n";
			break;
		}

	} 
	else {
		cout << "you want all cases \n";  
		cout << "you can enter sizes 3x3 or 2x2 only \n";
		int a, b, c, d;
		int matrix1[10][10];
		int matrix2[10][10];
		int matrix3[10][10] = { 0 };
		int matrix4[10][10] = { 0 }; 
		int matrix5[10][10] = { 0 };
		int deter1 = 0;
		float determinant = 0;
		cout << "enter size of first matrix \n";
		cin >> a >> b;
		cout << "enter size of second matrix \n";
		cin >> c >> d;
		if (a == c && b == d) {
			cout << "enter elements of first matrix\n";
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					cin >> matrix1[i][j];
				}
			}
			cout << "enter elements of second matrix\n";
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					cin >> matrix2[i][j];
				}
			}
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < d; j++) {
					for (int k = 0; k < c; k++) {
						matrix5[i][j] += matrix1[i][k] * matrix2[k][j];
					}

				}
			}
			cout << endl << "your multiplicated matrix is \n";
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					cout << matrix5[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "Subtracted matrix is \n";
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					matrix3[i][j] = matrix2[i][j] + matrix1[i][j];
				}
			}
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					matrix4[i][j] = matrix1[i][j] - matrix2[i][j];
				}
			}
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					cout << matrix4[i][j]<< " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "Added matrix is \n";
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					cout << matrix3[i][j] << " ";
				}
				cout << endl;
			}
			if (a == b && a == 2) {
				int array[2][2];
				cout << "please enter the elements of the matrix first one or second one  \n";
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < a; j++) {
						cin >> array[i][j];
					}
				}
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < b; j++) {
						deter1 = (array[0][0] * array[1][1] - array[1][0] * array[0][1]);
					}
				}
				cout << "the determinant of the matrix is " << deter1 << endl;

				invers_matrix2();

			}
			else if (a == b && a == 3) {
				int array[3][3];
				cout << "please enter the elements of the matrix first one or second one  \n";
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < a; j++) {
						cin >> array[i][j];
					}
				}
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < a; j++) {
						deter1 = array[0][0] * (array[2][2] * array[1][1] - array[2][1] * array[1][2]) - array[0][1] * (array[2][2] * array[1][0] - array[1][2] * array[2][0]) + array[0][2] * (array[2][1] * array[1][0] - array[1][1] * array[2][0]);
					}
				}
				cout << "the determinant of the matrix is " << deter1 << endl;
				printf("\nGiven matrix is:");
				for (int i = 0; i < 3; i++) {
					cout << "\n";

					for (int j = 0; j < 3; j++)
						cout << array[i][j] << "\t";
				}

				//finding determinant
				for (int i = 0; i < 3; i++)
					determinant = determinant + (array[0][i] * (array[1][(i + 1) % 3] * array[2][(i + 2) % 3] - array[1][(i + 2) % 3] * array[2][(i + 1) % 3]));

				cout << "\n\ndeterminant: " << determinant;

				cout << "\n\nInverse of matrix is: \n";
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++)
						cout << ((array[(j + 1) % 3][(i + 1) % 3] * array[(j + 2) % 3][(i + 2) % 3]) - (array[(j + 1) % 3][(i + 2) % 3] * array[(j + 2) % 3][(i + 1) % 3])) / determinant << "\t";

					cout << "\n";
				}

			}
		}
		else
			cout << "can't make the operation \n";



	}
	
	system("pause");
	return 0; 
}
	void addition_matrix() {
	
		int a, b, c, d;
		int matrix1[10][10];
		int matrix2[10][10];
		int matrix3[10][10] = { 0 };
		cout << "enter size of first matrix \n";
		cin >> a >> b;
		cout << "enter size of second matrix \n";
		cin >> c >> d;
		if (a == c && b == d) {
			cout << "enter elements of first matrix\n";
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					cin >> matrix1[i][j];
				}
			}
			cout << "enter elements of second matrix\n";
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					cin >> matrix2[i][j];
				}
			}
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					matrix3[i][j] = matrix2[i][j] + matrix1[i][j];
				}
			}
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					cout << matrix3[i][j] << " ";
				}
				cout << endl;
			}
		}
		else
			cout << "can't make the operation \n";
		 
}
void subtraction_matrix() {

	int a, b, c, d;
	int matrix1[10][10];
	int matrix2[10][10];
	int matrix3[10][10] = { 0 };
	cout << "enter size of first matrix \n";
	cin >> a >> b;
	cout << "enter size of second matrix \n";
	cin >> c >> d;
	if (a == c && b == d) {
		cout << "enter elements of first matrix\n";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> matrix1[i][j];
			}
		}
		cout << "enter elements of second matrix\n";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> matrix2[i][j];
			}
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
			}
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cout << matrix3[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "can't make the operation \n";
}
void multiplication_matrix() {

Back:
	int a, b, c, d;
	int matrix1[10][10];
	int matrix2[10][10];
	int matrix3[10][10] = { 0 };
	cout << "enter row of first matrix \n";
	cin >> a;
	cout << "enter colum of first matrix \n";
	cin >> b;
	cout << "enter row of second matrix \n";
	cin >> c;
	cout << "enter colum of second matrix \n";
	cin >> d;
	if (b == c) {
		cout << "enter elements of first matrix\n";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> matrix1[i][j];
			}
		}
		cout << "enter elements of first matrix\n";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> matrix2[i][j];
			}
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < d; j++) {
				for (int k = 0; k < c; k++) {
					matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
				}

			}
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cout << matrix3[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {

		cout << "can't make maltiplication \n";
		goto Back;
	}



}
void determ_matrix() {
	int a, b, deter1 = 0;
	cout << "please enter the size of matrix *** should be 3x3 or 2x2 only ***\n";
	cin >> a >> b;
	if (a == b && a == 2) {
		int array[2][2];
		cout << "please enter elements of the matrix \n";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> array[i][j];

			}

		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				deter1 = (array[0][0] * array[1][1] - array[1][0] * array[0][1]);
			}
		}
		cout << "the determinant of the matrix is " << deter1 << endl;
	}
	else if (a == b && a == 3) {
		int array[3][3];
		cout << "please enter the elements of the matrix \n";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				cin >> array[i][j];
			}
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				deter1 = array[0][0] * (array[2][2] * array[1][1] - array[2][1] * array[1][2]) - array[0][1] * (array[2][2] * array[1][0] - array[1][2] * array[2][0]) + array[0][2] * (array[2][1] * array[1][0] - array[1][1] * array[2][0]);
			}
		}
		cout << "the determinant of the matrix is " << deter1 << endl;
	}
	else {
		cout << "Not available matrix \n";
	}
}
void invers_matrix3(){
	int mat[3][3], i, j;
	float determinant = 0;

	cout << "Enter elements of matrix row wise:\n";
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			cin >> mat[i][j];

	printf("\nGiven matrix is:");
	for (i = 0; i < 3; i++) {
		cout << "\n";

		for (j = 0; j < 3; j++)
			cout << mat[i][j] << "\t";
	}

	//finding determinant
	for (i = 0; i < 3; i++)
		determinant = determinant + (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));

	cout << "\n\ndeterminant: " << determinant;

	cout << "\n\nInverse of matrix is: \n";
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			cout << ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant << "\t";

		cout << "\n";
	}
} 
void invers_matrix2() { 
	int a, b;
	cout << "please enter size of matrix \n";
	cin >> a >> b;
	if (a == b && a == 2) {


		double array1[2][2];
		cout << "you are in case of 2x2 inverse \n";
		cout << "enter elements of the matrix \n";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> array1[i][j];
			}
		}
		cout << array1[0][0] << "  " << array1[0][1] << endl;
		cout << array1[1][0] << "  " << array1[1][1] << endl;
		idol = array1[0][0];
		cout << idol << endl;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				deter = (array1[0][0] * array1[1][1] - array1[1][0] * array1[0][1]);
			}
		}
		cout << "your determinant is" << deter << endl;
		if (deter > 0) {
			array1[0][1] = -1.0 * (pow(deter, -1)) *array1[0][1];
			array1[1][0] = -1.0 * (pow(deter, -1)) * array1[1][0];
			array1[0][0] = (pow(deter, -1)) * array1[1][1];
			array1[1][1] = (pow(deter, -1)) * idol;
			cout << "inverse matrix \n";
			k = -1 * -1 * array1[0][0];
			l = -1 * -1 * array1[0][1];
			w = -1 * -1 * array1[1][0];
			q = -1 * -1 * array1[1][1];
			cout << k << " " << l << endl;
			cout << w << " " << q << endl;
		}
		if (deter < 0) {
			array1[0][1] = -1.0 * (pow(deter, -1)) *array1[0][1];
			array1[1][0] = -1.0 * (pow(deter, -1)) * array1[1][0];
			array1[0][0] = (pow(deter, -1)) * array1[1][1];
			array1[1][1] = (pow(deter, -1)) * idol;
			cout << "inverse matrix \n";
			k = -1 * array1[0][0];
			l = -1 * array1[0][1];
			w = -1 * array1[1][0];
			q = -1 * array1[1][1];
			cout << k << " " << l << endl;
			cout << w << " " << q << endl;



		}
	}

}
