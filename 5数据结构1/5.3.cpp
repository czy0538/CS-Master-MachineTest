#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct Animal
{
    int order;
    int no;
    Animal(int a, int b) : order(a), no(b) {}
};
void out_dog(queue<Animal> &dog)
{

}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        queue<Animal> cat;
        queue<Animal> dog;
        int m, t;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &m, &t);
            if (m == 1)
            {
                if (t > 0)
                {
                    dog.push(Animal(i, t));
                }
                else if (t < 0)
                {
                    cat.push(Animal(i, t));
                }
            }
            else if (m == 2)
            {
                switch (t)
                {
                case 0:
                    if (!dog.empty() && !cat.empty())
                    {
                        if (dog.front().order < cat.front().order)
                        {
                            printf("%d ", dog.front().no);
                            dog.pop();
                        }
                        else
                        {
                            printf("%d ", cat.front().no);
                            cat.pop();
                        }
                    }
                    else if (!dog.empty())
                    {
                        printf("%d ", dog.front().no);
                        dog.pop();
                    }
                    else if (!cat.empty())
                    {
                        printf("%d ", cat.front().no);
                        cat.pop();
                    }
                    break;
                case 1:
                    if (!dog.empty())
                    {
                        printf("%d ", dog.front().no);
                        dog.pop();
                    }
                    break;
                case -1:
                    if (!cat.empty())
                    {
                        printf("%d ", cat.front().no);
                        cat.pop();
                    }
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}