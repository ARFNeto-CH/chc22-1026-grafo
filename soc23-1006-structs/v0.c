#include <stdio.h>
#include "stuff.h"

int main(void) {
  Competition c1 = {1, 2, 3};
  Competition c2 = {4, 5, 6};
  Competition c3 = {7, 8, 9};

  School* school1 = so_sch_create(42, "Loveless Cafe", 20);
  so_sch_show(school1, "\n[SCHOOL just created]    ");

  so_sch_insert(&c1, school1);
  so_sch_insert(&c2, school1);
  so_sch_insert(&c3, school1); // inserted all competitions we have above
  so_sch_show(school1, "\n[some competitions inserted]    ");
  
  School* school2 = so_sch_create(42, "Cumberland", 20);
  so_sch_show(school2, "\n[SCHOOL just created]    ");
  so_sch_insert(&c3, school2); 
  so_sch_show(school2, "\n[some competitions inserted]    ");

  Zone* zone1 = so_zon_create(1717, "Tennessee", 12);
  so_zon_show(zone1, "\n\n[ZONE just created]    ");
  so_zon_insert(school1, zone1);
  so_zon_insert(school2, zone1);
  so_zon_show(zone1, "\n[ZONE has 2 schools now]    ");

  so_sch_destroy(school1);
  so_sch_destroy(school2);
  so_zon_destroy(zone1);
  return 0;
}
