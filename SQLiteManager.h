//
//  SQLiteManager.h
//
//  Created by Ester Sanchez on 10/03/11.
//  Copyright 2011 Dinamica Studios. All rights reserved.
//
//  Modified by Alex Jungwirth 09/04/11.
//  Copyright 2011 Jungwirth Media

//  Released under MIT License

#import <Foundation/Foundation.h>
#import "sqlite3.h"


enum errorCodes {
	kDBNotExists,
	kDBFailAtOpen, 
	kDBFailAtCreate,
	kDBErrorQuery,
	kDBFailAtClose
};

@interface SQLiteManager : NSObject {

	sqlite3 *db; // The SQLite db reference
	NSString *databaseName; // The database name
}

- (id)initWithDatabaseNamed:(NSString *)name;

// SQLite Operations
- (NSError *) openDatabase;
- (NSError *) doQuery:(NSString *)sql;
- (NSArray *) getRowsForQuery:(NSString *)sql;
- (NSError *) closeDatabase;

- (NSString *)getDatabaseDump;

@end
