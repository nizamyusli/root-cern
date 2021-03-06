// @(#)root/sqlite:$Id$
// Author: o.freyermuth <o.f@cern.ch>, 01/06/2013

/*************************************************************************
 * Copyright (C) 1995-2013, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TPgSQLRow
#define ROOT_TPgSQLRow

#ifndef ROOT_TSQLRow
#include "TSQLRow.h"
#endif

#if !defined(__CINT__)
#include <sqlite3.h>
#else
struct sqlite3_stmt;
#endif


class TSQLiteRow : public TSQLRow {

private:
   sqlite3_stmt *fResult;       // current result set
   Bool_t        IsValid(Int_t field);

public:
   TSQLiteRow(void *result, ULong_t rowHandle);
   ~TSQLiteRow();

   void        Close(Option_t *opt="");
   ULong_t     GetFieldLength(Int_t field);
   const char *GetField(Int_t field);

   ClassDef(TSQLiteRow,0)  // One row of SQLite query result
};

#endif
