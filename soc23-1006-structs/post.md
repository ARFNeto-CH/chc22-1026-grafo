When I try to access:

```C
school *cs = &(zones->school[0]); //Get the appropriate school
int schoolId = cs->school_id; //get the school id of a school
```

Your model is not complete. Writing this way makes it hard to get anything working. And to work an assortment of pointers and global counters would be needed. The more distant you  model is from reality the harder to code something to operate on the model.

## competitions, schools and zones ##
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
  - a pointer can point to a single competition but could also point to an array of `Competition` and a `size` is needed.
  - inside school we can be sure the `id`is for a school, so `id` is sufficient: All fields in `school` are school related anyway so we can avoid repeting school prefix everywhere. And it seems hard to have a negative id, so `unsigned` can save some tests.
  
Compare:    

```C
typedef struct {
  unsigned id;
  char* name;
  unsigned size;  // how many competitions?
  unsigned limit; // max value
  Competition* cmp;

} School;
```

So we have a name for the school, an id and a size for the array of competitions. And `cmp` as a short name is preferable over a giant `competition` name because we will probrably write if very often...    
And as the `struct` is created a `limit` is set for the array of `Competition` size.

### zones ###
````C
typedef struct zone {
    school* schools; //[School 0, School 1, School 2.....];
} zone;
```

Same problem here, or worse. A zone seems to be a set of schools, but has no name, no id, no size. And should also be anonymous.

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

We have `Competition`, `School` and `Zone` and it is clear that we will want to operate on this things. At a minimum we will want to create, destroy, display and insert into these structs. Thinking of classes, we need a constructor, a destructor, a `toString()` method like in _java_, and may be a copy constructor because we want not to trust on pointers inside structures that also have pointers...

But the `structs` are identical so we can copy and paste a lot. Almost no code to write.

Let us consider

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

Same names, 3-letter prefixes to identify target, but these are 5 to 10-lines functions copied one from another.

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



