#ifndef CONFIG_HXX
#define CONFIG_HXX

#include <Types.hxx>

namespace Config {
const QString BoolTypeName { "BOOLEAN" };
const QString IntTypeName { "INTEGER" };
const QString BigintTypeName { "BIGINT" };
const QString NumericTypeName { "NUMERIC" };
const QString TextTypeName { "TEXT" };
const QString DateTypeName { "DATE" };
const QString TimeTypeName { "TIME" };
const QString TimestampTypeName { "TIMESTAMP" };
const QString UuidTypeName { "UUID" };

const QString ApiSchemaName { "API" };
const QString DataSchemaName { "DATA" };
const QString AuditSchemaName { "AUDIT" };

const QString UuidExtensionName { "uuid-ossp" };

const QString FossilTypesTableName { "FOSSIL_TYPES" };

const QString IdColName { "ID" };
const QString IdTypeName { UuidTypeName };
}

#endif // CONFIG_HXX
