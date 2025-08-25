#pragma once

#include <QString>
#include <QMap>
#include <QDir>
#include <QFile>
#include <QVector>

// TODO: Add a file integrity checker class and load resource file names from a json file.
// Later on remove the RESOURCE_FILES (file embedding) from cmake, as I am copying the 
// required files at end of compilation into .exe file directory

class SqlQueryLoader 
{
public:
    SqlQueryLoader(const QString& queries_path);
    QStringList getDatabaseSchemaQueries() const;
    QStringList getDatabaseSeedQueries()  const;
    QString getQueryString(const QString& entity_tablename, const QString& query_name) const;

private:
    QString m_queries_path;
    QMap<QString, QString> m_queries_map;
    QMap<QString, QStringList> m_ordered_group_queries;

    QString readFile(const QString& file_path) const;
    QVariant loadOrderedGroupQueries(QString dir_path) const;
    void loadAllQueries();
};