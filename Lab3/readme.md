The programme uses Eigen library
To run the programme you need to: 
1. Download the library <http://eigen.tuxfamily.org/index.php?title=Main_Page>
2. Open the project properties page (Project | Properties), in the C/C++ folder open the General page, and after Additional Include Directories put EIGENDIR (the folder in which you store the Eigen library).
3. Compile and run the program.

***

The programme solves the task of modal control.

The input data are:
1. Number of rows(columns) of square matrix A (N)
2. Matrix A (NxN)
3. Number of columns of matrix B (M)
4. Matrix B (NxM)
5. N roots of characteristic equation (N real numbers)

The output:
1. Equation that describes the control process


