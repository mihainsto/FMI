#include <iostream>

class complex
{
    float m_re, m_im;
public:
    complex(int re, int im);
    complex();
    complex(int re);
    ~complex();
    //constructor de copiere
    complex(const complex&);
    friend std::istream &operator>>(std::istream &input, complex &);
    friend std::ostream &operator<<(std::ostream &output, complex &);
    void operator=(const complex&);
    complex operator+(const complex&);
    
};
std::istream &operator>>(std::istream &input, complex &C)
{
    input >> C.m_re;
    input >> C.m_im;
    return input;
}
std::ostream &operator<<(std::ostream &output, complex &C)
{
    output << C.m_re << " ";
    output << C.m_im << "\n";
    return output;
}

void complex::operator= (const complex &C)
{
    std::cout<<"operatorul = a fost apelat\n";
}
complex complex::operator+ (const complex &C)
{
    complex G;
    
    G.m_re += C.m_re + this->m_re;
    G.m_im += C.m_im + this->m_im;
    return G;
}
complex::complex(int re, int im)
{
    m_re = re;
    m_im = im;
}
complex::complex()
{
    m_re = 0;
    m_im = 0;
}
complex::complex(int re)
{
    m_re = re;
    m_im = 0;
}
complex::complex(const complex& C)
{
    std::cout<<"Constructor de copiere\n";
    this->m_re = C.m_re;
    this->m_im = C.m_im;
}
complex::~complex()
{
    std::cout<<"destructor pentru "<<m_re<<" "<<m_im<<"\n";
}
//examen:
/// doua obiecte suprascrise fara constructor de copiere -> ramane acelasi pointer
/// daca apelam constructor de copiere nesuprascris ne vin 2 obiecte cu acelasi pointer
/// nr5 = nr3 => vectorul nui nr5 e acelasi cu vectorul lui nr3
//examen:
///complex nr5
/// nr5 = nr3 <- nu e contructor de copiere - e defapt operatoru egal
int main() {
    complex C, C2(1), C3(1,2);
    
    std::cout<<C<<C2<<C3;
    
    complex *G = new complex(3,4);
    
    std::cout<<*G;
    delete G;
    complex C4 = C3;
    std::cout<<C4;
    C4 = C3;
    std::cout<<"\n";
    std::cout<<C4 << C3;
    complex C5 = C4 + C3;
    std::cout<<C5;
    return 0;
}

