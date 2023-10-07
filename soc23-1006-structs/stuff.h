#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int prize_1;
  int prize_2;
  int prize_3;

} Competition;
int so_cmp_show(Competition*, const char*);

typedef struct {
  unsigned     id;
  char*        name;
  unsigned     size;   // how many competitions?
  unsigned     limit;  // max value
  Competition* cmp;

} School;

School* so_sch_copy(School*);
School* so_sch_create(unsigned, const char*, unsigned);
School* so_sch_destroy(School*);
int     so_sch_insert(Competition*, School*);
int     so_sch_show(School*, const char*);

typedef struct {
  unsigned id;
  char* name;
  unsigned size;   // how many?
  unsigned limit;  // max value
  School** sc;      // array of schools
} Zone;

Zone* so_zon_create(unsigned, const char*, unsigned);
Zone* so_zon_destroy(Zone* Z);
int   so_zon_insert(School* S, Zone* Z);
int   so_zon_show(Zone* Z, const char* msg);
