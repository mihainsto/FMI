#include <iostream>
using namespace std;

struct pol
{
	int deg, val;
	pol *next;

};

void add_to_pol(pol *&first_pol, int x, int deg)
{
	pol *aux = new pol;
	aux->val = x;
	aux->deg = deg;
	if (first_pol == NULL) aux->next = NULL;
	else aux->next = first_pol;
	first_pol = aux;

}

void print_pol(pol *&first_pol)
{
	pol *aux;
	aux = first_pol;
	pol *nul = reinterpret_cast<pol*>(0xCCCCCCCC);

	while(aux != nul && aux != NULL)
	{
		cout << " + ";
		cout << aux->val << " *x^" << aux->deg;
		aux = aux->next;
	}
	cout << "\n";
}

void mult_pol__by_number(pol *&first_pol, int x)
{
	pol *aux;
	aux = first_pol;
	pol *nul = reinterpret_cast<pol*>(0xCCCCCCCC);

	while(aux != nul)
	{
		aux->val *= x;
		aux = aux->next;

	}
	
}
int poww(int x,int e)
{
	if (e == 0) return 1;
	int x1 = x;
	for (int i = 1; i < e; i++)
		x = x*x1;
	return x;
}
int pol_evaluate(pol *&first_pol, int x)
{    
	pol *aux;
	aux = first_pol;
	int result = 0;
	pol *nul = reinterpret_cast<pol*>(0xCCCCCCCC);

	while (aux != nul)
	{
		result += aux->val * (x, aux->deg);
		aux = aux->next;
	}
	return result;
}

void pol_sum(pol *&first_pol1, pol *&first_pol2, pol *&first_sumpol)
{
	pol *nul = reinterpret_cast<pol*>(0xCCCCCCCC);
	pol *aux_pol1 = first_pol1;
	pol *aux_pol2 = first_pol2;
	int coef_pol3, deg_pol3;

	while(( aux_pol1 != nul && aux_pol1) || ( aux_pol2 != nul && aux_pol2) )
	{
		coef_pol3 = 0; deg_pol3 = 0;
		if (aux_pol1 != nul && aux_pol1) coef_pol3 += aux_pol1->val, deg_pol3 = aux_pol1->deg, aux_pol1 = aux_pol1->next;
		if (aux_pol2 != nul && aux_pol2) coef_pol3 += aux_pol2->val, deg_pol3 = aux_pol2->deg, aux_pol2 = aux_pol2->next;
		add_to_pol(first_sumpol, coef_pol3, deg_pol3);
	}

}

void pol_sum(pol *&first_pol1, pol *&first_pol2)
{
	pol *nul = reinterpret_cast<pol*>(0xCCCCCCCC);
	pol *first_sumpol;
	pol_sum(first_pol1, first_pol2, first_sumpol);
	//delete first_pol1;
	first_pol1 = NULL;
	while(first_sumpol != nul)
	{
		add_to_pol(first_pol1, first_sumpol->val, first_sumpol->deg);
		first_sumpol = first_sumpol->next;
	}

}
void add_to_end_of_pol(pol *&first_pol, pol *&last_pol, int x, int deg)
{
	pol *nul = reinterpret_cast<pol*>(0xCCCCCCCC);
	pol *aux = new pol;
	aux->val = x;
	aux->deg = deg;
	aux->next = NULL;
	if (first_pol == NULL || first_pol == nul) { first_pol = aux; last_pol = aux; }
	else last_pol->next = aux;
	last_pol = aux;

}

void add_coef_to_pol(pol *first_pol, int x, int deg)
{
	pol *aux;
	aux = first_pol;
	pol *nul = reinterpret_cast<pol*>(0xCCCCCCCC);

	while (aux != nul && aux != NULL)
	{
		if (aux->deg == deg) { aux->val += x; return; }
		
		aux = aux->next;
	}
	

}

void pol_mult(pol *&first_pol1, pol *&first_pol2, pol *&first_multpol,int maxdeg)
{
	for (int i = 0; i <= maxdeg; i++)
		add_to_pol(first_multpol, 0, maxdeg - i);

	print_pol(first_multpol);

	pol *nul = reinterpret_cast<pol*>(0xCCCCCCCC);
	pol *aux_pol1 = first_pol1;
	pol *aux_pol2;
	int coef_pol3, deg_pol3, coef_pol1, deg_pol1, coef_pol2, deg_pol2;
	while (aux_pol1 != nul)
	{
		pol *first_pol_for_add, *last_pol_for_add;
		coef_pol1 = aux_pol1->val; deg_pol1 = aux_pol1->deg;
		aux_pol2 = first_pol2;
		while (aux_pol2 != nul)
		{
			coef_pol2 = aux_pol2->val; deg_pol2 = aux_pol2->deg;
			coef_pol3 = coef_pol1 * coef_pol2;
			deg_pol3 = deg_pol1 + deg_pol2;
			add_coef_to_pol(first_multpol, coef_pol3,deg_pol3);
			aux_pol2 = aux_pol2->next;
		}

		aux_pol1 = aux_pol1->next;
		print_pol(first_multpol);
	}
	
}
int main()
{
	int n, m, x,deg;
	 pol *first_pol1, *first_pol2;
	cout << "Deg pol1:\n";
	cin >> n;
	cout << "Coef pol1:\n";
	deg = n;
	for(int i=1;i<=n+1;i++)
	{
		cin >> x; add_to_pol(first_pol1, x, deg);
		deg--;
	}

	cout << "Deg pol2:\n";
	cin >> m;
	cout << "Coef pol2:\n";
	deg = m;
	for (int i = 1; i <= m+1; i++)
	{
		cin >> x; add_to_pol(first_pol2, x, deg);
		deg--;
	}
	print_pol(first_pol1);
	print_pol(first_pol2);

	cout << "pol1 mult by:";
	cin >> x;
	mult_pol__by_number(first_pol1, x);
	print_pol(first_pol1);

	cout << "pol2 evaluate with x="; cin >> x;
	cout << pol_evaluate(first_pol2, x);
	cout << "\n";

	pol *first_sumpol;
	pol_sum(first_pol1, first_pol2, first_sumpol);
	print_pol(first_sumpol);
	
	
	
	pol *first_multpol;
	int maxdeg;
	maxdeg = n + m;
	pol_mult(first_pol1, first_pol2, first_multpol, maxdeg);
	print_pol(first_multpol);
	
	system("pause");

}
