#ifndef MODEL_H
#define MODEL_H

#include <QMap>
#include <QSet>
#include <QString>
#include <QVariant>

class Model : public QMap<QString, QVariant>
{
    friend class Builder;

    enum class Flag { INVALID };

public:
    Model();
    virtual ~Model();

    QString get(const QString &key) const;
    int getInt(const QString &key) const;
    void set(const QString &key, const QVariant &value);

    virtual int id() const;
    QStringList dirtyKeys() const;

    operator bool() const;

    static Model invalid();

    bool exists;

private:
    Model(Flag);
    bool valid;

protected:
    QMap<QString, QVariant> original;
};

#include "inloquentmodel.h"

#endif // MODEL_H
