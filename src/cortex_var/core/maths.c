/*
 * Copyright 2009-2011 Zamin Iqbal and Mario Caccamo  
 * 
 * CORTEX project contacts:  
 * 		M. Caccamo (mario.caccamo@bbsrc.ac.uk) and 
 * 		Z. Iqbal (zam@well.ox.ac.uk)
 *
 * **********************************************************************
 *
 * This file is part of CORTEX.
 *
 * CORTEX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CORTEX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CORTEX.  If not, see <http://www.gnu.org/licenses/>.
 *
 * **********************************************************************
 */

#include <math.h>
#include <maths.h>
#include <stdlib.h>


// log(n!)= sum from i=1 to n, of  (log(i))                                                                                                                                                                          
float log_factorial(int number)
{
  if (number<0)
    {
      printf("Do not call log_factorial with negative argument %d\n", number);
      exit(1);
    }
  int i;
  float ret=0;
  for (i=1; i<=number; i++)
    {
      ret+=log(i);
    }
  return ret;
}


float log_factorial_ll(long long number)
{
  if (number<0)
    {
      printf("Do not call log_factorial with negative argument %lld\n", number);
      exit(1);
    }
  long long i;
  float ret=0;
  for (i=1; i<=number; i++)
    {
      ret+=log(i);
    }
  return ret;
}

int min_of_ints(int a, int b)
{
  if (a<b)    
    {
      return a;
    }
  else
    {
      return b;
    }
}