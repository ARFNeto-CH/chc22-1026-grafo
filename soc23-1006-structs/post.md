
```C
school *cs = &(zones->school[0]); //Get the appropriate school
int schoolId = cs->school_id; //get the school id of a school
```

Your model is not complete. Writing this way makes it hard to get anything working. And for it to work an assortment of pointers and global counters would be needed. The more distant you  model is from reality the harder to code something to operate on the model.

I will show you a way of allocate memory correctly, and also a way to write this kind of program step by step. I will not even say that this is a god one, but worked here at first try, and in general it does work at first time.

I did minimal testing. Errors are not checked in `main` but a negative value is often returned from all functions in case of error.

It is a long post since I will be coding, copying and pasting here.

The idea is to encapsulate all data into `structs`, use only pointers for the `structs` and treat them like classes in other languages.

## Competitions, Schools and Zones ##
### Competition ###

```C
typedef struct competition {
    int prize_1;
    int prize_2;
    int prize_3;
} competition;
```

This is ok but the `struct` should be anonymous. And there is a silent convention of reserving the first letter in uppercase for `typedef`ed things. Let us use
```C
typedef struct
{   int prize_1;
    int prize_2;
    int prize_3;

}   Competition;
```

## schools ##
```C
typedef struct school {
    int school_id;
    competition* competitions;//[Singing, Dancing, Soccer....]

} school;
```

This one also should be anonymous. But school is only a `pointer` and an `int`. This is not sufficient:    
  - how many competitions in school? You need to know. This is why every `C` program gets `argc` and `argv`. A container needs a `size` counter, possibly 2, `size` and `limit`
  - a pointer can point to a single competition but could also point to an array of `Competition` so a `size` is needed.
  - inside school we can be sure the `id`is for a school, so `id` is sufficient: All fields in `school` are school related anyway, so we can avoid repeting school prefix everywhere. And it seems hard to have a negative id, so `unsigned` can save some tests.
  
Compare:    

```C
typedef struct {
  unsigned     id;
  char*        name;
  unsigned     size;  // how many competitions?
  unsigned     limit; // max value
  Competition* cmp;

} School;
```

So now we also have a name for the school, an id and a size for the array of competitions. And `cmp` as a short name is preferable over a giant `competition` name because we will probrably write if very often...    
And as the `struct` is created a `limit` is set for the array of `Competition` size. We do not want the program crashing for writing beyond buffer. We want no external counter to manage

### zones ###
````C
typedef struct zone {
    school* schools; //[School 0, School 1, School 2.....];
} zone;
```

Same problem here, or worse. A zone seems to be a set of schools, but has no name, no id, no size. And should also be anonymous.

Let us just copy `School` to `Zone`


Compare with the trivial
```C
typedef struct
{
	int      id;
	char*    name;
	unsigned size; // how many?
	unsigned limit; // max value
	School** sc;  // array of schools
}   Zone;
```

Using `sc` as an array of pointers is easier, more or less like 
```C
        int main(int argc, char** argv);
```

So we have more manageable prototypes using

```C
typedef struct {
  int prize_1;
  int prize_2;
  int prize_3;

} Competition;

typedef struct {
  unsigned id;
  char* name;
  unsigned size;  // how many competitions?
  unsigned limit; // max value
  Competition* cmp;

} School;

typedef struct
{
	unsigned id;
	char* name;
	unsigned size; // how many?
	unsigned limit; // max value
	School** sc;  // array of schools
}   Zone;
```

### creating schools and zones ###

We have `Competition`, `School` and `Zone` and it is clear that we will want to operate on this things. At a minimum we will want to create, destroy, display and insert into these structs. Thinking of classes, we need a constructor, a destructor, a `toString()` method like in _java_, and may be a copy constructor because we want not to trust on pointers inside structures that also have pointers, so we will copy data before insert.

But the `structs` are identical so we can copy and paste a lot. Almost no code to write.

**Let us consider**

```C
int so_cmp_show(Competition*, const char*);

School* so_sch_copy(School*);
School* so_sch_create(unsigned, const char*, unsigned);
School* so_sch_destroy(School*);
int     so_sch_insert(Competition*, School*);
int     so_sch_show(School*, const char*);

Zone* so_zon_create(unsigned, const char*, unsigned);
Zone* so_zon_destroy(Zone* Z);
int   so_zon_insert(School* S, Zone* Z);
int   so_zon_show(Zone* Z, const char* msg);
```

Same names, 3-letter prefixes to identify target, but these are 5 to 10-lines functions copied one from another. No globals, no external counters.

It they do work, a program like this:

```C
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
```

should run and display something like
```none

[SCHOOL just created]      School #42: "Loveless Cafe": 0/20 competitions

[some competitions inserted]      School #42: "Loveless Cafe": 3/20 competitions
                1,2,3
                4,5,6
                7,8,9

[SCHOOL just created]      School #42: "Cumberland": 0/20 competitions

[some competitions inserted]      School #42: "Cumberland": 1/20 competitions
                7,8,9


[ZONE just created]        #1717: "Tennessee": 0/12 competitions

[ZONE has 2 schools now]        #1717: "Tennessee": 2/12 competitions
  School #42: "Loveless Cafe": 3/20 competitions
                1,2,3
                4,5,6
                7,8,9
  School #42: "Cumberland": 1/20 competitions
                7,8,9
    destroying record of zone "Tennessee"
```

And we can go for other tasks. And it worked...

## complete code ##

### stuff.h ###
```C
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
```

### stuff.c: all functions ###
```C
#include "stuff.h"
#include <memory.h>

int so_cmp_show(Competition* C, const char* msg) {
  if (C == NULL)
    return -1;
  if (msg != NULL)
    printf("%s", msg);
  printf("\t\t%d,%d,%d\n", C->prize_1, C->prize_2, C->prize_3);
  return 0;
}

int so_sch_show(School* S, const char* msg) {
  if (S == NULL)
    return -1;
  if (msg != NULL)
    printf("%s", msg);
  printf("  School #%d: \"%s\": %d/%d competitions\n", S->id, S->name, S->size,
         S->limit);
  for (unsigned i = 0; i < S->size; i += 1)
    so_cmp_show(&S->cmp[i], NULL);
  return 0;
}

School* so_sch_copy(School* S) {
  if (S == NULL)
    return NULL;
  School* copy = so_sch_create(S->id, S->name, S->limit);
  if (copy == NULL)
    return NULL;
  // competitions are contiguous in memory
  memcpy(copy->cmp, S->cmp, sizeof(Competition) * S->size);
  copy->size = S->size;
  return copy;
}

School* so_sch_create(unsigned id, const char* name, unsigned size) {
  if (name == NULL)
    return NULL;
  if (size == 0)
    return NULL;
  School* nw = malloc(sizeof(School));
  if (nw == NULL)
    return NULL;
  nw->id = id;
  nw->name = malloc(1 + strlen(name));
  if (nw->name == NULL) {
    free(nw);
    return NULL;
  }
  strcpy(nw->name, name);
  nw->limit = size;
  nw->size = 0;  // empty
  nw->cmp = malloc(nw->limit * sizeof(Competition));
  if (nw->cmp == NULL) {
    free(nw->name);
    free(nw);
    return NULL;
  }
  return nw;
}

School* so_sch_destroy(School* sc) {
  if (sc == NULL)
    return NULL;
  free(sc->name);  // name
  free(sc->cmp);   // array
  free(sc);        // struct
  return NULL;
}

int so_sch_insert(Competition* cmp, School* S) {
  if (cmp == NULL)
    return -1;  // no competition
  if (S == NULL)
    return -2;  // no school
  if (S->size >= S->limit)
    return -3;  // full
  S->cmp[S->size] = *cmp;
  S->size += 1;
  return 0;
}

Zone* so_zon_create(unsigned id, const char* name, unsigned size) {
  if (name == NULL)
    return NULL;
  if (size == 0)
    return NULL;
  Zone* nw = malloc(sizeof(Zone));
  if (nw == NULL)
    return NULL;
  nw->id = id;
  nw->name = malloc(1 + strlen(name));
  if (nw->name == NULL) {
    free(nw);
    return NULL;
  }
  strcpy(nw->name, name);
  nw->limit = size;
  nw->size = 0;  // empty
  // pointers for schools
  nw->sc = (School**)malloc(nw->limit*sizeof(School*));
  if (nw->sc == NULL) {
    free(nw->name);
    free(nw);
    return NULL;
  }
  for (unsigned i = 0; i < nw->limit; i += 1)
      nw->sc[i] = NULL;
  return nw;
}

Zone* so_zon_destroy(Zone* zone) {
  if (zone == NULL)
    return NULL;
  fprintf(stderr, "    destroying record of zone \"%s\"\n", zone->name);
  free(zone->name);  // name
  for (unsigned i = 0; i < zone->size; i += 1)
    so_sch_destroy(zone->sc[i]);
  free(zone->sc);  // array
  free(zone);      // struct
  return NULL;
}

int so_zon_insert(School* S, Zone* Z) {
  if (S == NULL)
    return -1;  // no school
  if (Z == NULL)
    return -2;  // no zone
  if (Z->size >= Z->limit)
    return -3;  // full
  // inserts a school
  Z->sc[Z->size] = so_sch_copy(S);
  Z->size += 1;
  return 0;
}

int so_zon_show(Zone* Z, const char* msg) {
  if (Z == NULL)
    return -1;
  if (msg != NULL)
    printf("%s", msg);
  printf("    #%d: \"%s\": %d/%d competitions\n", Z->id, Z->name, Z->size,
         Z->limit);
  for (unsigned i = 0; i < Z->size; i += 1)
    so_sch_show(Z->sc[i], NULL);
  return 0;
}
```

### main.c ###
```C
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
```




