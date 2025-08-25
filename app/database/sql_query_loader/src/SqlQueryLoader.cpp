#include "SqlQueryLoader.h"

SqlQueryLoader::SqlQueryLoader(const QString& queries_path) 
    : m_queries_path {queries_path}
{
    loadAllQueries();
}


QString SqlQueryLoader::readFile(const QString& file_path) const {
    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file: " << file_path;
        return QString();
    }
    QTextStream input_text_stream(&file);
    return input_text_stream.readAll();
}


QVariant SqlQueryLoader::loadOrderedGroupQueries(QString dir_path) const {
    QDir queries_dir(m_queries_path + dir_path);
    QString dir_name = dir_path.replace("/", "");
    if(!queries_dir.exists()) {
        return QVariant{};
    }
    auto query_files = queries_dir.entryList(QStringList() << "*.sql", QDir::Files, QDir::Name);
    query_files.sort();
    QStringList queries_list;
    for (const auto& query_file : query_files) {
        QString query_string = readFile(queries_dir.filePath(query_file));
        queries_list.append(std::move(query_string));
    }
    return queries_list;
}


void SqlQueryLoader::loadAllQueries() {
    QDir queries_dir(m_queries_path + "/queries");
    if (queries_dir.exists()) {
        auto entities = queries_dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for (const auto& entity: entities) {
            QDir entity_dir(queries_dir.filePath(entity));
            auto query_files = entity_dir.entryList(QStringList() << "*.sql", QDir::Files, QDir::Name);
            for (const auto& query_file: query_files) {
                QString query_name = query_file.section(".", 0, 0);
                QString query_string = readFile(entity_dir.filePath(query_file));
                QString query_key = entity + "_" + query_name;
                m_queries_map.insert(query_key, query_string);
            }
        }
    } else {
        qDebug() << "':qrc/app/resources/sql/queries' DIR NOT FOUND!";
    }

    auto schema_queries = loadOrderedGroupQueries("/schema");
    if (schema_queries.isValid()) {
        m_ordered_group_queries.insert("schema", schema_queries.value<QStringList>());
    }

    auto seeds_queries = loadOrderedGroupQueries("/seeds");
    if (seeds_queries.isValid()) {
        m_ordered_group_queries.insert("seeds", seeds_queries.value<QStringList>());
    }
}


QStringList SqlQueryLoader::getDatabaseSchemaQueries() const {
    auto it = (m_ordered_group_queries.find("schema"));
    if (it != m_ordered_group_queries.end()) {
        return *it;
    }
    return QStringList();
}


QStringList SqlQueryLoader::getDatabaseSeedQueries()  const {
    auto it = (m_ordered_group_queries.find("seeds"));
    if (it != m_ordered_group_queries.end()) {
        return *it;
    }
    return QStringList();
}


QString SqlQueryLoader::getQueryString(const QString& entity_tablename, const QString& query_name) const {
    QString query_key = entity_tablename + "_" + query_name;
    auto it = m_queries_map.find(query_key);
    if (it != m_queries_map.end()) {
        return *it;
    }
    return QString();
}
