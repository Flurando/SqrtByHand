#include <math.h>
#include <stdio.h>
#include <stddef.h>

int
solve (int lastdigit, int wantednum, int p[2])
{
  printf ("[Solve Func]Lastdigit: %d, Wantednum: %d\n", lastdigit, wantednum);
  int test = 0;
  int check = 0;
  int lasttest = 0;
  while (1)
  {
    printf ("trying test = %d\n", test);
    check = 20 * lastdigit * test + pow (test, 2);
    printf ("the corresponding check value is %d\n", check);
    if (check > wantednum) break;
    else puts ("seems that check <= wantednum, continuing");
    lasttest = test;
    test++;
  }
  int nowdigit = lasttest;
  printf ("nowdigit: %d\n", nowdigit);
  p[0] = nowdigit;
  p[1] = wantednum - (20 * lastdigit * nowdigit + pow (nowdigit, 2));
  printf ("[solve func]editing nowdigit to be %d and remain to be %d\n", p[0], p[1]);
  return 1;
}

int
main (void)
{
  int ans = 0;
  int num = 0;
  int numlen = 0;
  puts ("Please input the number and how many digits it has you want:");
  scanf ("%d %d", &num, &numlen);
  
  /*if (numlen % 2 == 0)
  {
    int poolsize = numlen / 2;
  }
  else
  {
    int poolsize = numlen / 2 + 1;
  }*/
  int needtweat = (numlen % 2 == 1);
  if (needtweat)
  {
    numlen = numlen + 1;
  }
  int poolsize = numlen / 2;
  printf ("poolsize: %d\n", poolsize);
  int pool[poolsize];
  puts ("inited pool");
  int fakenum = num;
  puts ("3");
  int remainednums = numlen - 2;
  
  printf ("remainednums: %d\n", remainednums);
  for (int index = 0; index <= poolsize; index++)
  {
    int tempmod = pow (10, remainednums);
    pool[index] = fakenum / tempmod;
    printf ("we apply %d to pool[%d]\n", pool[index], index);
    fakenum = fakenum % tempmod;
    remainednums = remainednums - 2;
    if (remainednums < 0) break;
  }
  
  int counter = 0;
  int lastdigit = 0;
  int remain = 0;
  while (counter < poolsize)
  {
    printf ("Let's note %d\n", counter);
    int wantednum = 100 * remain + pool[counter];
    printf ("The wantednum is %d now.\n", wantednum);
    int tempholder[2];
    solve (lastdigit, wantednum, tempholder);
    int nowdigit = tempholder[0];
    remain = tempholder[1];
    ans = ans * 10 + nowdigit;
    lastdigit = nowdigit;
    counter++;
  }
  
  printf ("For %d, My answer is: %d\n", num, ans);
  
  return 0;
}
