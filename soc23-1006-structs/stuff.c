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
