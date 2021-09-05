#include<iostream>
#include"p0_starter.h"
using namespace std;

void  testRowMatrix()
{
	//testRowMatrix
	RowMatrix<int> test1(2,3);   //创建 RowMatrix实例
	cout << "test1的rows是:" << test1.GetRowCount() << endl << endl;
	cout << "test1的cols是:" << test1.GetColumnCount() << endl << endl;
	cout << "SetElement设置矩阵的元素全为1" << endl << endl;
	for(int i=0;i<test1.GetRowCount();i++)
	    for(int j=0;j<test1.GetColumnCount();j++)
		    test1.SetElement(i,j,1);
	cout << "GetElement查看矩阵中元素:" << endl << endl;
	for(int i=0;i<test1.GetRowCount();i++)
	{
		for(int j=0;j<test1.GetColumnCount();j++)
		    cout << test1.GetElement(i,j) << " ";
		cout << endl;
    }
    cout << endl;
    cout << "FillFrom设置矩阵元素并用GetElement查看：" << endl << endl;
    int a[6]={1,2,3,4,5,6};
	vector <int> b(a,a+6);  
	test1.FillFrom(b);
	for(int i=0;i<test1.GetRowCount();i++)
	{
		for(int j=0;j<test1.GetColumnCount();j++)
		    cout << test1.GetElement(i,j) << " ";
		cout << endl;
    }
    cout << endl;
}

void testRowMatrixOperations_Add()
{
	RowMatrixOperations<int> op;
	
	cout << "使用Add函数并用GetElement查看结果：" << endl;

	RowMatrix<int> A(2,3);
	vector<int> sourceA(6, 1);
	A.FillFrom(sourceA);
	
	RowMatrix<int> B(2,3);
	vector<int> sourceB(6, 2);
	B.FillFrom(sourceB);
	/* A+B=?
	A: 1 1 1
	   1 1 1
	B: 2 2 2
	   2 2 2
	*/
	
	std::unique_ptr<RowMatrix<int>> C=op.Add(&A,&B);
	for(int i=0;i<C->GetRowCount();i++)
	{
		for(int j=0;j<C->GetColumnCount();j++)
		{
			cout << C->GetElement(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void testRowMatrixOperations_Multiply()
{
	cout << "使用Multiply函数并用GetElement查看结果：" << endl;
	RowMatrixOperations<int> op;
	
	RowMatrix<int> A(2,3);
	vector<int> sourceA(6, 1);
	A.FillFrom(sourceA);
	
	RowMatrix<int> B(3,2);
	vector<int> sourceB(6, 2);
	B.FillFrom(sourceB);
	
	/* A*B=?
	A: 1 1 1
	   1 1 1
	B: 2 2 
	   2 2 
	   2 2
	*/
	std::unique_ptr<RowMatrix<int>> Mul = op.Multiply(&A, &B);;
	for(int i=0;i<Mul->GetRowCount();i++)
	{
		for(int j=0;j<Mul->GetColumnCount();j++)
		{
			cout << Mul->GetElement(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void testRowMatrixOperations_GEMM()
{
	cout << "使用GEMM函数并用GetElement查看结果：" << endl;
	RowMatrixOperations<int> op;
	RowMatrix<int> A(2,3);
	vector<int> sourceA(6, 1);
	A.FillFrom(sourceA);
	
	RowMatrix<int> B(3,2);
	vector<int> sourceB(6, 2);
	B.FillFrom(sourceB);
	
	RowMatrix<int> C(2,2);
	vector<int> sourceC(4, 3);
	C.FillFrom(sourceC);
	
	/* A*B+C=?
	A: 1 1 1
	   1 1 1
	B: 2 2 
	   2 2 
	   2 2
	C: 3 3
	   3 3
	*/
	std::unique_ptr<RowMatrix<int>> Gem = op.GEMM(&A, &B,&C);
	for(int i=0;i<Gem->GetRowCount();i++)
	{
		for(int j=0;j<Gem->GetColumnCount();j++)
		{
			cout << Gem->GetElement(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main(){
	
	cout << "*********下面测试RowMatrix中的函数功能*********" << endl << endl;
	testRowMatrix();
	cout << "*********下面测试RowMatrixOperations中的函数功能*********" << endl << endl;
	testRowMatrixOperations_Add();
	testRowMatrixOperations_Multiply();
	testRowMatrixOperations_GEMM();
	
	return 0;
} 
