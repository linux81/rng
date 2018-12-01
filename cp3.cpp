#include<iostream>
#include<stack>
#include <gsl/gsl_rng.h>
#include <time.h>

int
main (void)
{

  std::stack < double > sts;	
  const gsl_rng_type * T;
  gsl_rng * r;

  int i, n = 10;

  gsl_rng_env_setup();

  T = gsl_rng_default;
  r = gsl_rng_alloc (T);
  gsl_rng_set(r,time(0));

  for (i = 0; i < n; i++)
    {
      double u = gsl_rng_uniform (r);
      std::cout<<u<<"\n";
      sts.push(u);
    }
std::cout<<sts.fron()<<"\n";
std::cout<<sts.size()<<"\n";
sts.pop();
std::cout<<sts.size()<<"\n";
std::cout<<sts.front()<<"\n";
  gsl_rng_free (r);

  return 0;
}
