#ifndef CONFIG_HXX
#define CONFIG_HXX

namespace Config {
const QString BoolTypeName { "BOOLEAN" };
const QString IntTypeName { "INTEGER" };
const QString BigintTypeName { "BIGINT" };
const QString NumericTypeName { "NUMERIC" };
const QString UuidTypeName { "UUID" };
const QString TextTypeName { "TEXT" };
const QString TimestampTypeName { "TIMESTAMP" };
const QString TimeTypeName { "TIME" };
const QString DateTypeName { "DATE" };

const QString DataSchemaName { "DATA" };
const QString ApiSchemaName { "API" };
const QString AuditSchemaName { "AUDIT" };

const QString UuidExtensionName { "\"uuid-ossp\"" };

namespace Columns {
const QString IDColName { "ID" };
const QString IdTypeName { UuidTypeName };

const QString VersionColName { "VERSION" };
const QString VersionTypeName { BigintTypeName };

const QString CreatorColName { "CREATOR" };
const QString CreatorTypeName { TextTypeName };

const QString CreationColName { "CREATED" };
const QString CreationTypeName { TimestampTypeName };

const QString ModificatorColName { "MODIFICATOR" };
const QString ModificatorTypeName { TextTypeName };

const QString ModificationColName { "MODIFIED" };
const QString ModificationTypeName { TimestampTypeName };
}

namespace Tables {
const QString FossilTypes { "FOSSIL_TYPES" };
const QString Fossils { "FOSSILS" };
}
}
#endif // CONFIG_HXX
