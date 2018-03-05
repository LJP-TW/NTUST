#include <stdio.h>
 
int main()
{
    int _intersection[10] = { 0 };
    int _intersection_pointer = 0;
    int _union[10] = { 0 };
    int _union_pointer = 0;
    int first_array[5];
    int second_array[5];
    int flag;
    int temp;
 
    while (scanf(" %d", &first_array[0]) != EOF)
    {
        for (int i = 1; i < 5; i++)
        {
            scanf(" %d", &first_array[i]);
        }
        for (int i = 0; i < 5; i++)
        {
            scanf(" %d", &second_array[i]);
        }
 
        /* init */
        _intersection_pointer = 0;
        _union_pointer = 0;
 
        /* intersection judge */
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (first_array[i] == second_array[j])
                {
                    _intersection[_intersection_pointer] = first_array[i];
                    _intersection_pointer += 1;
                    break;
                }
            }
        }
 
        /* union judge */
        for (int i = 0; i < 5; i++)
        {
            _union[_union_pointer] = first_array[i];
            _union_pointer += 1;
        }
        for (int i = 0; i < 5; i++)
        {
            flag = 1;
            for (int j = 0; j < _union_pointer; j++)
            {
                if (second_array[i] == _union[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                _union[_union_pointer] = second_array[i];
                _union_pointer += 1;
            }
        }
 
        /* debug */
        /*
        for (int i = 0; i < _intersection_pointer; i++)
            printf("%d ", _intersection[i]);
        printf("\n");
        for (int i = 0; i < _union_pointer; i++)
            printf("%d ", _union[i]);
        printf("\n");
        */
 
        /*  */
        for (int i = _intersection_pointer; i > 0; i--)
        {
            for (int j = 0; j < i - 1; j++)
            {
                if (_intersection[j] > _intersection[j + 1])
                {
                    temp = _intersection[j];
                    _intersection[j] = _intersection[j + 1];
                    _intersection[j + 1] = temp;
                }
            }
        }
 
        for (int i = _union_pointer; i > 0; i--)
        {
            for (int j = 0; j < i - 1; j++)
            {
                if (_union[j] > _union[j + 1])
                {
                    temp = _union[j];
                    _union[j] = _union[j + 1];
                    _union[j + 1] = temp;
                }
            }
        }
 
        /* debug */
        /*
        for (int i = 0; i < _intersection_pointer; i++)
        printf("%d ", _intersection[i]);
        printf("\n");
        for (int i = 0; i < _union_pointer; i++)
        printf("%d ", _union[i]);
        printf("\n");
        */
 
        /* PrintOut*/
        printf(" Intersection is: { ");
        for (int i = 0; i < _intersection_pointer; i++)
            printf("%d ", _intersection[i]);
        printf("}\n");
        printf(" Union is: { ");
        for (int i = 0; i < _union_pointer; i++)
            printf("%d ", _union[i]);
        printf("}\n");
    }
    return 0;
}