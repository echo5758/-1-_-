#include <memory>
#include <stdexcept>
#include <vector>
#include<iostream>
#include<cstring>
using namespace std;
	
template <typename T>
class Matrix {
	
 protected:
  Matrix(int rows, int cols) 
    {
  	  this->rows_=rows;
  	  this->cols_=cols;
  	  this->linear_=new T[rows*cols];
  	  memset(linear_, 0, sizeof(T) * rows * cols);
  	  //cout << "成功创建了一个" << rows << "*" << cols << "的Matrix" << endl << endl;
    }
  int rows_;
  int cols_;
  T *linear_;

 public:
  virtual int GetRowCount() const = 0;
  virtual int GetColumnCount() const = 0;
  virtual T GetElement(int i, int j) const = 0;
  virtual void SetElement(int i, int j, T val) = 0;
  virtual void FillFrom(const std::vector<T> &source) = 0;
  virtual ~Matrix()
  {
  	delete []linear_;
  	//cout << "成功销毁Matrix" << endl << endl; 
  }
};

template <typename T>
class RowMatrix : public Matrix<T> {
 public:
  RowMatrix(int rows, int cols) : Matrix<T>(rows, cols) 
  {
  	data_=new T * [rows];
  	for(int i=0; i<this->rows_;i++)
	{
  	    this->data_[i]= & this->linear_[i*this->cols_];
  	}
  	//cout << "成功创建了一个" << rows << "*" << cols << "的RowMatrix" << endl << endl;
  }
  int GetRowCount() const override { return this->rows_; }
  int GetColumnCount() const override { return this->cols_; }
  T GetElement(int i, int j) const override {return data_[i][j];}
  void SetElement(int i, int j, T val) override {data_[i][j]=val;}
  
  void FillFrom(const std::vector<T> &source) override {
    for(int i=0;i<GetRowCount();i++)
        for(int j=0;j<GetColumnCount();j++)
        	data_[i][j]=source[i*GetColumnCount()+j];
  }
  
  ~RowMatrix() override 
  {
    delete[] data_;
    //cout << "成功销毁RowMatrix" << endl  << endl;
  }

 private:
  T **data_;
};

template <typename T>
class RowMatrixOperations {
 public:

  static std::unique_ptr<RowMatrix<T>> Add(const RowMatrix<T> *matrixA, const RowMatrix<T> *matrixB) {
    if(matrixA->GetRowCount()==matrixB->GetRowCount() && matrixA->GetColumnCount()==matrixB->GetColumnCount()) 
    {
    	int row = matrixA->GetRowCount();
		int col = matrixA->GetColumnCount();
    	std::unique_ptr<RowMatrix<T>> matrixC(new RowMatrix<T>(row, col));  //!!!
    	for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<col;j++)
    		{
    			matrixC->SetElement(i,j,matrixA->GetElement(i,j)+matrixB->GetElement(i,j));
			}
		}
		return matrixC;
	}
	else 
	    return std::unique_ptr<RowMatrix<T>>(nullptr);
  }

  static std::unique_ptr<RowMatrix<T>> Multiply(const RowMatrix<T> *matrixA, const RowMatrix<T> *matrixB) {
    if(matrixA->GetColumnCount()==matrixB->GetRowCount())
    {
    	int row = matrixA->GetRowCount();
		int col = matrixB->GetColumnCount();
    	std::unique_ptr<RowMatrix<T>> matrixC(new RowMatrix<T>(row, col));
    	for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<col;j++)
    		{
    			for(int y=0;y<matrixA->GetColumnCount();y++)
    			{
    				T temp=matrixC->GetElement(i, j);
    				temp+=matrixA->GetElement(i,y)*matrixB->GetElement(y,j);
    				matrixC->SetElement(i,j,temp);
				}
    			
			}
		}
		return matrixC;
	}
	else
	    return std::unique_ptr<RowMatrix<T>>(nullptr);
  }

  static std::unique_ptr<RowMatrix<T>> GEMM(const RowMatrix<T> *matrixA, const RowMatrix<T> *matrixB,const RowMatrix<T> *matrixC) 
   {
    if(matrixA->GetColumnCount()==matrixB->GetRowCount()&&matrixA->GetRowCount()==matrixC->GetRowCount()&&matrixB->GetColumnCount()==matrixC->GetColumnCount())
    {
    	int row = matrixC->GetRowCount();
		int col = matrixC->GetColumnCount();
    	std::unique_ptr<RowMatrix<T>> matrixD(new RowMatrix<T>(row, col));
		matrixD=Multiply(matrixA,matrixB);
		for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<col;j++)
    		{
    			matrixD->SetElement(i,j,matrixC->GetElement(i,j)+matrixD->GetElement(i,j));
			}
		}
		return matrixD;
	}
	else
	    return std::unique_ptr<RowMatrix<T>>(nullptr);
  }
};

