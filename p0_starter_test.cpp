#include<iostream>
#include"p0_starter.h"
using namespace std;

void  testRowMatrix()
{
	//testRowMatrix
	RowMatrix<int> test1(2,3);   //���� RowMatrixʵ��
	cout << "test1��rows��:" << test1.GetRowCount() << endl << endl;
	cout << "test1��cols��:" << test1.GetColumnCount() << endl << endl;
	cout << "SetElement���þ����Ԫ��ȫΪ1" << endl << endl;
	for(int i=0;i<test1.GetRowCount();i++)
	    for(int j=0;j<test1.GetColumnCount();j++)
		    test1.SetElement(i,j,1);
	cout << "GetElement�鿴������Ԫ��:" << endl << endl;
	for(int i=0;i<test1.GetRowCount();i++)
	{
		for(int j=0;j<test1.GetColumnCount();j++)
		    cout << test1.GetElement(i,j) << " ";
		cout << endl;
    }
    cout << endl;
    cout << "FillFrom���þ���Ԫ�ز���GetElement�鿴��" << endl << endl;
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
	
	cout << "ʹ��Add��������GetElement�鿴�����" << endl;

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
	cout << "ʹ��Multiply��������GetElement�鿴�����" << endl;
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
	cout << "ʹ��GEMM��������GetElement�鿴�����" << endl;
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
	
	cout << "*********�������RowMatrix�еĺ�������*********" << endl << endl;
	testRowMatrix();
	cout << "*********�������RowMatrixOperations�еĺ�������*********" << endl << endl;
	testRowMatrixOperations_Add();
	testRowMatrixOperations_Multiply();
	testRowMatrixOperations_GEMM();
	
	return 0;
} 
