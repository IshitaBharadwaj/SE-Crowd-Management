#include<bits/stdc++.h>
using namespace std;



vector<pair<char,int>> v;


int ppl_a=0,ppl_b=0,ppl_c=0;


solve(vector<pair<char,int>> v){

    for(auto x:v){
        int pi_a=0;
        int pi_b=0;
        int pi_c=0;
        int po_a=0;
        int po_b=0;
        int po_c=0;
        if(x.first=='A'){if(x.second==0){pi_a=1;}else{po_a=1;}}
        if(x.first=='B'){if(x.second==0){pi_b=1;}else{po_b=1;}}
        if(x.first=='C'){if(x.second==0){pi_c=1;}else{po_c=1;}}
        if ((ppl_a != 10 || ppl_b != 10))
            {

                if ((po_a == 1 || po_b == 1))
                {
                    if (ppl_a < ppl_b)
                    {
                        cout<<("Enter terminal A")<<endl;;
                        ppl_a++;

                        // delay(1000);
                    }
                    else if (ppl_b < ppl_a)
                    {
                        cout<<("Enter terminal B")<<endl;;
                        ppl_b++;
                        // delay(1000);
                    }
                    else
                    {
                        if (po_a == 1)
                        {
                            cout<<("Enter terminal A")<<endl;;
                            ppl_a++;

                            // delay(1000);
                        }
                        else if (po_b == 1)
                        {
                            cout<<("Enter terminal B")<<endl;;
                            ppl_b++;
                            // delay(1000);
                        }
                    }
                    cout<<("Current count for terminal A: ");
                    cout<<(ppl_a)<<endl;;
                    cout<<("Current count for terminal B: ");
                    cout<<(ppl_b)<<endl;;
                    if (ppl_c)
                    {
                        cout<<("Current count for terminal C: ");
                        cout<<(ppl_c)<<endl;;
                    }
                    // delay(1000);
                }
                if (pi_a == 1 && ppl_a > 0)
                {
                    ppl_a--;
                    // delay(500);
                    cout<<("Exiting terminal A")<<endl;;
                    cout<<("Current count for terminal A: ");
                    cout<<(ppl_a)<<endl;;
                    cout<<("Current count for terminal B: ");
                    cout<<(ppl_b)<<endl;;
                    if (ppl_c)
                    {
                        cout<<("Current count for terminal C: ");
                        cout<<(ppl_c)<<endl;;
                    }

                    // delay(1000);
                }
                else if (pi_a == 1 && ppl_a == 0)
                {
                    cout<<("No customers in A")<<endl;;
                    // delay(1000);
                }
                if (pi_b == 1 && ppl_b > 0)
                {
                    ppl_b--;
                    // delay(500);
                    cout<<("Exiting terminal B")<<endl;;
                    cout<<("Current count for terminal A: ");
                    cout<<(ppl_a)<<endl;;
                    cout<<("Current count for terminal B: ");
                    cout<<(ppl_b)<<endl;;
                    if (ppl_c)
                    {
                        cout<<("Current count for terminal C: ");
                        cout<<(ppl_c)<<endl;;
                    }
                    // delay(1000);
                }
                else if (pi_b == 1 && ppl_b == 0)
                {
                    cout<<("No customers in B")<<endl;
                    // delay(1000);
                }
                if (pi_c == 1 && ppl_c > 0)
                {
                    ppl_c--;
                    // delay(500);
                    cout<<("Exiting terminal C")<<endl;;
                    cout<<("Current count for terminal A: ");
                    cout<<(ppl_a)<<endl;;
                    cout<<("Current count for terminal B: ");
                    cout<<(ppl_b)<<endl;;
                    cout<<("Current count for terminal C: ");
                    cout<<(ppl_c)<<endl;;
                    // delay(1000);
                }
                else if (pi_c == 1 && ppl_c == 0)
                {
                    cout<<("No customers in C")<<endl;
                    // delay(1000);
                }
            }
            else
            {
                if ((po_a == 1 || po_b == 1) && ppl_c < 10 && ppl_c >= 0)
                {
                    if (ppl_c == 0)
                        cout<<("Opening terminal C ")<<endl;;

                    cout<<("Enter terminal C")<<endl;;
                    ppl_c++;
                    cout<<("Current count for terminal A: ");
                    cout<<(ppl_a)<<endl;;
                    cout<<("Current count for terminal B: ");
                    cout<<(ppl_b)<<endl;;
                    cout<<("Current count for terminal C: ");
                    cout<<(ppl_c)<<endl;;
                }
                else if (ppl_c != 0 && ppl_c != 10 && po_c == 1)
                {
                    cout<<("Enter terminal C")<<endl;;
                    ppl_c++;
                    cout<<("Current count for terminal A: ");
                    cout<<(ppl_a)<<endl;;
                    cout<<("Current count for terminal B: ");
                    cout<<(ppl_b)<<endl;;
                    cout<<("Current count for terminal C: ");
                    cout<<(ppl_c)<<endl;;
                }
                else
                {
                    if (po_a == 1 || po_b == 1 || po_c == 1)
                        cout<<("Please wait, POS are crowded ")<<endl;;
                }
                if (pi_a == 1 && ppl_a > 0)
                {
                    ppl_a--;
                    // delay(500);
                    cout<<("Exiting terminal A")<<endl;
                    cout<<("Current count for terminal A: ");
                    cout<<(ppl_a)<<endl;;
                    cout<<("Current count for terminal B: ");
                    cout<<(ppl_b)<<endl;;
                    cout<<("Current count for terminal C: ");
                    cout<<(ppl_c)<<endl;;
                    // delay(1000);
                }
                else if (pi_a == 1 && ppl_a == 0)
                {
                    cout<<("No customers in A")<<endl;
                    // delay(1000);
                }
                if (pi_b == 1 && ppl_b > 0)
                {
                    ppl_b--;
                    // delay(500);
                    cout<<("Exiting terminal B")<<endl;;
                    cout<<("Current count for terminal A: ");
                    cout<<(ppl_a)<<endl;;
                    cout<<("Current count for terminal B: ");
                    cout<<(ppl_b)<<endl;;
                    cout<<("Current count for terminal C: ");
                    cout<<(ppl_c)<<endl;;
                    // delay(1000);
                }
                else if (pi_b == 1 && ppl_b == 0)
                {
                    cout<<("No customers in B")<<endl;;
                    // delay(1000);
                }
                if (pi_c == 1 && ppl_c > 0)
                {
                    ppl_c--;
                    // delay(500);
                    cout<<("Exiting terminal C")<<endl;;
                    cout<<("Current count for terminal A: ");
                    cout<<(ppl_a)<<endl;;
                    cout<<("Current count for terminal B: ");
                    cout<<(ppl_b)<<endl;;
                    cout<<("Current count for terminal C: ");
                    cout<<(ppl_c)<<endl;;
                    // delay(1000);
                }
                else if (pi_c == 1 && ppl_c == 0)
                {
                    cout<<("No customers in C")<<endl;;
                    cout<<("Closing terminal C")<<endl;;
                    // delay(1000);
                }
                // delay(1000);
            }
        }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("test.txt", "r", stdin);
    // freopen("output1.txt", "w", stdout);
    
    char c;int k;
    while(cin>>c && cin>>k){
        v.push_back({c,k});
    }
    solve(v);
}