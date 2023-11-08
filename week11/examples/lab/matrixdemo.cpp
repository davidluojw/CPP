#include <iostream>
#include <memory>


class Matrix
{
  private:
    size_t rows;
    size_t cols;
    
  public:
    std::shared_ptr<float> data;
    Matrix(size_t r, size_t c)
    {
        std::cout << "Constructor Matrix(r, c) " << std::endl;
        if ( r * c == 0)
        {
            rows = 0;
            cols = 0;
            data = nullptr;
        }
        else{
            rows = r;
            cols = c;
            std::shared_ptr<float> temp(new float[r * c]);
            data = temp;
        }
    }

    Matrix(const Matrix & m): rows(m.rows), cols(m.cols), data(m.data){ 
        std::cout << "Constructor Matrix(M) " << std::endl;
    }

    ~Matrix() {std::cout << "Destructor Matrix " << std::endl; }


    friend std::ostream & operator<<(std::ostream & os, const Matrix & m)
    {
        os << "size (" << m.rows << "x" << m.cols << ")" << std::endl;
        os << "[" << std::endl;
        for (size_t r = 0; r < m.rows; r++)
        {
            for(size_t c = 0; c < m.cols; c++)
                os << m.data.get()[r * m.cols + c] << ", ";
            os << std::endl;
        }
        os << "]";
        return os;
    }

    Matrix operator+(const Matrix &m)
    {
        std::cout << "Matrix Add " << std::endl;
        if (this->cols != m.cols || this->rows != m.rows)
        {
            std::cout << "The two matrices dimension must be the same. " << std::endl;
        }
        Matrix sum(m.rows, m.cols);
        size_t ind = 0;
        for (size_t r = 0; r < m.rows; r++)
        {
            for (size_t c = 0; c < m.cols; c++)
            {
                ind = r * m.cols + c;
                sum.data.get()[ind] = this->data.get()[ind] + m.data.get()[ind];
            }
        }

        return sum;

    }



    void setElement (int a, int b, float x)
    {   
        this->data.get()[a * this->cols + b] = x;
    }

    float getElement (int a, int b)
    {
        return this->data.get()[a * this->cols + b];
    }

};

int main()
{
    Matrix m1(3,8);
    Matrix m2(4,8);
    std::cout << "&m1 = " << &m1 << std::endl;
    std::cout << "&m2 = " << &m2 << std::endl;
    std::cout << "m1.data = " << m1.data << std::endl;
    std::cout << "m2.data = " << m2.data << std::endl;
    std::cout << "m1.data.get() = " << m1.data.get() << std::endl;
    std::cout << "m2.data.get() = " << m2.data.get() << std::endl;

    m2 = m1;
    std::cout << "&m1 = " << &m1 << std::endl;
    std::cout << "&m2 = " << &m2 << std::endl;
    std::cout << "m1.data = " << m1.data << std::endl;
    std::cout << "m2.data = " << m2.data << std::endl;
    std::cout << "m1.data.get() = " << m1.data.get() << std::endl;
    std::cout << "m2.data.get() = " << m2.data.get() << std::endl;
   
    m1.setElement(1, 2, 4.5f);
    std::cout << m2.getElement(1,2) << std::endl;

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    Matrix m3 = m1 + m2;
    std::cout << "&m1 = " << &m1 << std::endl;
    std::cout << "&m2 = " << &m2 << std::endl;
    std::cout << "&m3 = " << &m3 << std::endl;
    std::cout << "m1.data = " << m1.data << std::endl;
    std::cout << "m2.data = " << m2.data << std::endl;
    std::cout << "m3.data = " << m3.data << std::endl;
    std::cout << "m1.data.get() = " << m1.data.get() << std::endl;
    std::cout << "m2.data.get() = " << m2.data.get() << std::endl;
    std::cout << "m3.data.get() = " << m3.data.get() << std::endl;

    Matrix m4 = m1;
    std::cout << "&m1 = " << &m1 << std::endl;
    std::cout << "&m2 = " << &m2 << std::endl;
    std::cout << "&m3 = " << &m3 << std::endl;
    std::cout << "&m4 = " << &m3 << std::endl;
    std::cout << "m1.data = " << m1.data << std::endl;
    std::cout << "m2.data = " << m2.data << std::endl;
    std::cout << "m3.data = " << m3.data << std::endl;
    std::cout << "m4.data = " << m4.data << std::endl;
    std::cout << "m1.data.get() = " << m1.data.get() << std::endl;
    std::cout << "m2.data.get() = " << m2.data.get() << std::endl;
    std::cout << "m3.data.get() = " << m3.data.get() << std::endl;
    std::cout << "m4.data.get() = " << m4.data.get() << std::endl;



    std::cout << m3 << std::endl;
    std::cout << m4 << std::endl;
    


    return 0;
}