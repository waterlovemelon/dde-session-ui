// SPDX-FileCopyrightText: 2015 - 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef DBUSLOGIN1MANAGER_H_1447400884
#define DBUSLOGIN1MANAGER_H_1447400884

#include"dbusvariant.h"
#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freedesktop.login1.Manager
 */
class DBusLogin1Manager: public QDBusAbstractInterface
{
    Q_OBJECT
    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName !="org.freedesktop.login1.Manager")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        QStringList keys = changedProps.keys();
        foreach(const QString &prop, keys) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
                Q_EMIT p.notifySignal().invoke(this);
                }
            }
        }
   }
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.login1.Manager"; }

public:
    DBusLogin1Manager(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~DBusLogin1Manager();

    Q_PROPERTY(QString BlockInhibited READ blockInhibited NOTIFY BlockInhibitedChanged)
    inline QString blockInhibited() const
    { return qvariant_cast< QString >(property("BlockInhibited")); }

    Q_PROPERTY(QString ControlGroupHierarchy READ controlGroupHierarchy)
    inline QString controlGroupHierarchy() const
    { return qvariant_cast< QString >(property("ControlGroupHierarchy")); }

    Q_PROPERTY(QStringList Controllers READ controllers)
    inline QStringList controllers() const
    { return qvariant_cast< QStringList >(property("Controllers")); }

    Q_PROPERTY(QString DelayInhibited READ delayInhibited)
    inline QString delayInhibited() const
    { return qvariant_cast< QString >(property("DelayInhibited")); }

    Q_PROPERTY(QString HandleHibernateKey READ handleHibernateKey)
    inline QString handleHibernateKey() const
    { return qvariant_cast< QString >(property("HandleHibernateKey")); }

    Q_PROPERTY(QString HandleLidSwitch READ handleLidSwitch)
    inline QString handleLidSwitch() const
    { return qvariant_cast< QString >(property("HandleLidSwitch")); }

    Q_PROPERTY(QString HandlePowerKey READ handlePowerKey)
    inline QString handlePowerKey() const
    { return qvariant_cast< QString >(property("HandlePowerKey")); }

    Q_PROPERTY(QString HandleSuspendKey READ handleSuspendKey)
    inline QString handleSuspendKey() const
    { return qvariant_cast< QString >(property("HandleSuspendKey")); }

    Q_PROPERTY(QString IdleAction READ idleAction)
    inline QString idleAction() const
    { return qvariant_cast< QString >(property("IdleAction")); }

    Q_PROPERTY(qulonglong IdleActionUSec READ idleActionUSec)
    inline qulonglong idleActionUSec() const
    { return qvariant_cast< qulonglong >(property("IdleActionUSec")); }

    Q_PROPERTY(bool IdleHint READ idleHint)
    inline bool idleHint() const
    { return qvariant_cast< bool >(property("IdleHint")); }

    Q_PROPERTY(qulonglong IdleSinceHint READ idleSinceHint)
    inline qulonglong idleSinceHint() const
    { return qvariant_cast< qulonglong >(property("IdleSinceHint")); }

    Q_PROPERTY(qulonglong IdleSinceHintMonotonic READ idleSinceHintMonotonic)
    inline qulonglong idleSinceHintMonotonic() const
    { return qvariant_cast< qulonglong >(property("IdleSinceHintMonotonic")); }

    Q_PROPERTY(qulonglong InhibitDelayMaxUSec READ inhibitDelayMaxUSec)
    inline qulonglong inhibitDelayMaxUSec() const
    { return qvariant_cast< qulonglong >(property("InhibitDelayMaxUSec")); }

    Q_PROPERTY(QStringList KillExcludeUsers READ killExcludeUsers)
    inline QStringList killExcludeUsers() const
    { return qvariant_cast< QStringList >(property("KillExcludeUsers")); }

    Q_PROPERTY(QStringList KillOnlyUsers READ killOnlyUsers)
    inline QStringList killOnlyUsers() const
    { return qvariant_cast< QStringList >(property("KillOnlyUsers")); }

    Q_PROPERTY(bool KillUserProcesses READ killUserProcesses)
    inline bool killUserProcesses() const
    { return qvariant_cast< bool >(property("KillUserProcesses")); }

    Q_PROPERTY(uint NAutoVTs READ nAutoVTs)
    inline uint nAutoVTs() const
    { return qvariant_cast< uint >(property("NAutoVTs")); }

    Q_PROPERTY(bool PreparingForShutdown READ preparingForShutdown)
    inline bool preparingForShutdown() const
    { return qvariant_cast< bool >(property("PreparingForShutdown")); }

    Q_PROPERTY(bool PreparingForSleep READ preparingForSleep)
    inline bool preparingForSleep() const
    { return qvariant_cast< bool >(property("PreparingForSleep")); }

    Q_PROPERTY(QStringList ResetControllers READ resetControllers)
    inline QStringList resetControllers() const
    { return qvariant_cast< QStringList >(property("ResetControllers")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> ActivateSession(const QString &id)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("ActivateSession"), argumentList);
    }

    inline QDBusPendingReply<> ActivateSessionOnSeat(const QString &id, const QString &seat)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id) << QVariant::fromValue(seat);
        return asyncCallWithArgumentList(QLatin1String("ActivateSessionOnSeat"), argumentList);
    }

    inline QDBusPendingReply<> AttachDevice(const QString &seat, const QString &sysfs, bool interactive)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(seat) << QVariant::fromValue(sysfs) << QVariant::fromValue(interactive);
        return asyncCallWithArgumentList(QLatin1String("AttachDevice"), argumentList);
    }

    inline QDBusPendingReply<QString> CanHibernate()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("CanHibernate"), argumentList);
    }

    inline QDBusPendingReply<QString> CanHybridSleep()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("CanHybridSleep"), argumentList);
    }

    inline QDBusPendingReply<QString> CanPowerOff()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("CanPowerOff"), argumentList);
    }

    inline QDBusPendingReply<QString> CanReboot()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("CanReboot"), argumentList);
    }

    inline QDBusPendingReply<QString> CanSuspend()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("CanSuspend"), argumentList);
    }

//    inline QDBusPendingReply<QString, QDBusObjectPath, QDBusObjectPath, QDBusUnixFileDescriptor, QString, uint, bool> CreateSession(uint uid, uint leader, const QString &service, const QString &type, const QString &class, const QString &seat, uint vtnr, const QString &tty, const QString &display, bool remote, const QString &remote_user, const QString &remote_host, const QStringList &controllers, const QStringList &reset_controllers, bool kill_processes)
//    {
//        QList<QVariant> argumentList;
//        argumentList << QVariant::fromValue(uid) << QVariant::fromValue(leader) << QVariant::fromValue(service) << QVariant::fromValue(type) << QVariant::fromValue(class) << QVariant::fromValue(seat) << QVariant::fromValue(vtnr) << QVariant::fromValue(tty) << QVariant::fromValue(display) << QVariant::fromValue(remote) << QVariant::fromValue(remote_user) << QVariant::fromValue(remote_host) << QVariant::fromValue(controllers) << QVariant::fromValue(reset_controllers) << QVariant::fromValue(kill_processes);
//        return asyncCallWithArgumentList(QLatin1String("CreateSession"), argumentList);
//    }
//    inline QDBusReply<QString> CreateSession(uint uid, uint leader, const QString &service, const QString &type, const QString &class, const QString &seat, uint vtnr, const QString &tty, const QString &display, bool remote, const QString &remote_user, const QString &remote_host, const QStringList &controllers, const QStringList &reset_controllers, bool kill_processes, QDBusObjectPath &path, QDBusObjectPath &runtime_path, QDBusUnixFileDescriptor &fd, QString &seat_, uint &vtnr_, bool &existing)
//    {
//        QList<QVariant> argumentList;
//        argumentList << QVariant::fromValue(uid) << QVariant::fromValue(leader) << QVariant::fromValue(service) << QVariant::fromValue(type) << QVariant::fromValue(class) << QVariant::fromValue(seat) << QVariant::fromValue(vtnr) << QVariant::fromValue(tty) << QVariant::fromValue(display) << QVariant::fromValue(remote) << QVariant::fromValue(remote_user) << QVariant::fromValue(remote_host) << QVariant::fromValue(controllers) << QVariant::fromValue(reset_controllers) << QVariant::fromValue(kill_processes);
//        QDBusMessage reply = callWithArgumentList(QDBus::Block, QLatin1String("CreateSession"), argumentList);
//        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 7) {
//            path = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
//            runtime_path = qdbus_cast<QDBusObjectPath>(reply.arguments().at(2));
//            fd = qdbus_cast<QDBusUnixFileDescriptor>(reply.arguments().at(3));
//            seat_ = qdbus_cast<QString>(reply.arguments().at(4));
//            vtnr_ = qdbus_cast<uint>(reply.arguments().at(5));
//            existing = qdbus_cast<bool>(reply.arguments().at(6));
//        }
//        return reply;
//    }

    inline QDBusPendingReply<> FlushDevices(bool interactive)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(interactive);
        return asyncCallWithArgumentList(QLatin1String("FlushDevices"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> GetSeat(const QString &id)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("GetSeat"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> GetSession(const QString &id)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("GetSession"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> GetSessionByPID(uint pid)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(pid);
        return asyncCallWithArgumentList(QLatin1String("GetSessionByPID"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> GetUser(uint uid)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(uid);
        return asyncCallWithArgumentList(QLatin1String("GetUser"), argumentList);
    }

    inline QDBusPendingReply<> Hibernate(bool interactive)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(interactive);
        return asyncCallWithArgumentList(QLatin1String("Hibernate"), argumentList);
    }

    inline QDBusPendingReply<> HybridSleep(bool interactive)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(interactive);
        return asyncCallWithArgumentList(QLatin1String("HybridSleep"), argumentList);
    }

    inline QDBusPendingReply<QDBusUnixFileDescriptor> Inhibit(const QString &what, const QString &who, const QString &why, const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(what) << QVariant::fromValue(who) << QVariant::fromValue(why) << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("Inhibit"), argumentList);
    }

    inline QDBusPendingReply<> KillSession(const QString &id, const QString &who, const QString &signal)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id) << QVariant::fromValue(who) << QVariant::fromValue(signal);
        return asyncCallWithArgumentList(QLatin1String("KillSession"), argumentList);
    }

    inline QDBusPendingReply<> KillUser(uint uid, const QString &signal)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(uid) << QVariant::fromValue(signal);
        return asyncCallWithArgumentList(QLatin1String("KillUser"), argumentList);
    }

    inline QDBusPendingReply<InhibitorsList> ListInhibitors()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("ListInhibitors"), argumentList);
    }

    inline QDBusPendingReply<SeatList> ListSeats()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("ListSeats"), argumentList);
    }

    inline QDBusPendingReply<SessionList> ListSessions()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("ListSessions"), argumentList);
    }

    inline QDBusPendingReply<UserList> ListUsers()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("ListUsers"), argumentList);
    }

    inline QDBusPendingReply<> LockSession(const QString &id)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("LockSession"), argumentList);
    }

    inline QDBusPendingReply<> LockSessions()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("LockSessions"), argumentList);
    }

    inline QDBusPendingReply<> PowerOff(bool interactive)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(interactive);
        return asyncCallWithArgumentList(QLatin1String("PowerOff"), argumentList);
    }

    inline QDBusPendingReply<> Reboot(bool interactive)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(interactive);
        return asyncCallWithArgumentList(QLatin1String("Reboot"), argumentList);
    }

    inline QDBusPendingReply<> ReleaseSession(const QString &id)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("ReleaseSession"), argumentList);
    }

    inline QDBusPendingReply<> SetUserLinger(uint uid, bool b, bool interactive)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(uid) << QVariant::fromValue(b) << QVariant::fromValue(interactive);
        return asyncCallWithArgumentList(QLatin1String("SetUserLinger"), argumentList);
    }

    inline QDBusPendingReply<> Suspend(bool interactive)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(interactive);
        return asyncCallWithArgumentList(QLatin1String("Suspend"), argumentList);
    }

    inline QDBusPendingReply<> TerminateSeat(const QString &id)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("TerminateSeat"), argumentList);
    }

    inline QDBusPendingReply<> TerminateSession(const QString &id)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("TerminateSession"), argumentList);
    }

    inline QDBusPendingReply<> TerminateUser(uint uid)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(uid);
        return asyncCallWithArgumentList(QLatin1String("TerminateUser"), argumentList);
    }

    inline QDBusPendingReply<> UnlockSession(const QString &id)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("UnlockSession"), argumentList);
    }

    inline QDBusPendingReply<> UnlockSessions()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("UnlockSessions"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void BlockInhibitedChanged();

    void PrepareForShutdown(bool active);
    void PrepareForSleep(bool active);
    void SeatNew(const QString &id, const QDBusObjectPath &path);
    void SeatRemoved(const QString &id, const QDBusObjectPath &path);
    void SessionNew(const QString &id, const QDBusObjectPath &path);
    void SessionRemoved(const QString &id, const QDBusObjectPath &path);
    void UserNew(uint uid, const QDBusObjectPath &path);
    void UserRemoved(uint uid, const QDBusObjectPath &path);
};

namespace org {
  namespace freedesktop {
    namespace login1 {
      typedef ::DBusLogin1Manager Manager;
    }
  }
}
#endif
