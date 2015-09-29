#pragma once
#include <math.h>
#include <string>
using namespace std;


class Complex
{
private:
	double Re;
	double Im;
	double Mod;
	//friend istream& operator >> (istream &is, Complex&a);
	//friend ostream& operator << (ostream &os, const Complex&a);
	void MathMod()
	{
		Mod = sqrt(Re*Re + Im*Im);
	}
	void strtow(string st, string *w, int &k)
	{
		st += " ";
		w = new string[3];
		k = 0;
		w[0] = " ";
		for (int i = 0; i < st.length(); i++)
		{
			if ((st[i] == '+') || (st[i] == 'i'))
			{
				if (w[k] == " ")
				{
					w[k] = st[i];
				}
				else
				{
					w[++k] = st[i];
				}
			}
			else
			{
				if (st[i] != ' ')
				{
					w[++k] = "";
				}
				else
				{
					w[k] += st[i];
				}
			}
		}
	}
public:

	Complex(double fRe, double fIm)
	{
		Re = fRe;
		Im = fIm;
		MathMod();
	};

	Complex(Complex &tmp)
	{
		Re = tmp.Re;
		Im = tmp.Im;
		MathMod();
	};
	~Complex();
	Complex tocomplex(string str)
	{
		string *w;
		int k;
		strtow(str, w, k);
		Re = 0;
		Im = 0;
		for (int i = 0; i < k; i++)
		{
			if (w[i].find("i") == -1)
			{

			}
			else
			{
				int l = w[i].find("i");
				w[i].erase(l, 1);
			}
			if ((w[i] == "") || (w[i] == "+") || (w[i] == "-"))
			{
				w[i] += "1";
				Im = atof(w[i]);
			}
		}
	}
	Complex &operator= (Complex second)
	{
		Re = second.Re;
		Im = second.Im;
		MathMod();
		return *this;
	};

	Complex operator+ (Complex second)
	{
		Complex tmp;
		tmp.Re = Re + second.Re;
		tmp.Im = Im + second.Im;
		MathMod();
		return tmp;
	};

	Complex operator- (Complex second)
	{
		Complex tmp;
		tmp.Re = Re - second.Re;
		tmp.Im = Im - second.Im;
		MathMod();
		return tmp;
	};

	Complex operator* (Complex second)
	{
		Complex tmp;
		tmp.Re = Re*second.Re * Im*second.Im;
		tmp.Im = Re*second.Im * Im*second.Re;
		MathMod();
		return tmp;
	};

	Complex operator* (int second)
	{
		Complex tmp;
		tmp.Re = Re*second;
		tmp.Im = Im*second;
		tmp.Mod = Mod*second;
		return tmp;
	};

	Complex operator/ (Complex second)
	{
		Complex tmp;
		double kv = second.Mod;
		tmp.Re = (Re*second.Re + Im*second.Im) / kv;
		tmp.Im = (Im*second.Re + Re*second.Im) / kv;
		MathMod();
		return tmp;
	};

	Complex operator/ (int second);
	void Input(string st);
	void Print();

	double GetRe()
	{
		return Re;
	}
	void SetRe(double r)
	{
		Re = r;
		MathMod();
	}
	double GetIm()
	{
		return Im;
	}
	void GetIm(double r)
	{
		Im = r;
		MathMod();
	}
	double GetMod()
	{
		return Mod;
	}
	friend istream& operator >> (istream &is, Complex&a)
	{
		string tmp;
		is >> tmp;
		a.tocomplex(tmp);
		return is;
	}
	friend ostream& operator << (ostream &os, const Complex&a)
	{
		if (a.Re != 0)
		{
			os << a.Re;
			if (a.Im < 0)
			{
				os << a.Im << "i" << endl;
			}
			else
			{
				if (a.Im > 0)
				{
					os << "+" << a.Im << "i" << endl;
				}
			}
		}
		else
		{
			if (a.Im != 0)
			{
				os << a.Im << "i" << endl;
			}
			else
			{
				os << "0" << endl;
			}
		}
	}
	/*
Complex::
Complex(double fRe, double fIm)
{
Re = fRe;
Im = fIm;
MathMod();
};
Complex::
Complex(Complex &tmp)
{
Re = tmp.Re;
Im = tmp.Im;
MathMod();
};
Complex::~Complex()
{

};*/


};





