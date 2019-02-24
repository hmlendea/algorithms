#include <stdio.h>

// Generati toate permutarile de dimensiune n(1..n), cu propritatea ca pentru orice i 2<=i<=n
// exista un j, 1<=j<=i astfel incat |v(i)-v(j)|=1.

void bt_init (int st[], int k)
{
    st[k]=0;
}

int bt_succesor (int st[], int n, int k)
{
    if (st[k] < n)
    {
    	st[k] += 1;
    	return 1;
    }
    else
    	return 0;
}

int bt_valid (int st[], int k)
{
    int i;
    
    for (i = 1; i < k; i++)
	    if (st[i] == st[k])
	        return 0;
    return 1;
}

int bt_solutie (int st[], int n, int k)
{
    int i, j, dif;
    int ok, ok2;

    ok = 1;

    if (k == n)
        for (i = 2; i <= n; i++)
        {
            ok2 = 0;
            
            for (j = 1; j <= i; j++)
            {
                dif = st[i] - st[j];
            
                if (dif == 1 || dif == -1)
                {
                    ok2 = 1;
                    break;
                }
            }
            
            if (ok2 == 0)
            {
                ok = 0;
                break;
            }
        }
    else
        ok = 0;

	return ok;
}

void bt_tiparire (int st[], int n)
{
    int i;
    
	for (i = 1; i <= n; i++)
		printf("%d ", st[i]);
	printf("\n");
}

void bt(int n)
{
    int st[20];
    int as, ev;
    int k = 1;

	bt_init(st, k);

	while (k > 0)
	{
		as = 1;
		ev = 0;

		while (as && !ev)
		{
			as = bt_succesor (st, n, k);
			
			if (as)
				ev = bt_valid(st, k);
		}
		
		if (as)
		{
			if (bt_solutie (st, n, k))
				bt_tiparire (st, n);
			else
			{
				k += 1;
				bt_init (st, k);
			}
		}
		else k -= 1;
	}
}

int main (int argc, char* argv[])
{
    int n;
    
	printf ("n = ");
	scanf ("%d", &n);
	
	bt(n);
	
	return 0;
}
