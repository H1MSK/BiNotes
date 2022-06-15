#ifndef ACTIONS_H
#define ACTIONS_H

#include <QObject>
#include "singleton.h"
class QAction;

class Actions : public QObject, public Singleton<Actions>
{
    Q_OBJECT
public:
    Actions();
    ~Actions();

    QAction* hideWindowAction();
    QAction* showWindowAction();
    QAction* hideSettingsAction();
    QAction* removeMemoAction();
    QAction* flushTitlesAction();
    QAction* monitorForegroundAction();
    QAction* autoRunAction();
    QAction* quitProgramAction();

signals:
    void hideWindowTriggered();
    void showWindowTriggered();
    void hideSettingsToggled(bool checked);
    void removeMemoTriggered();
    void flushTitlesTriggered();
    void monitorForegroundToggled(bool checked);
    void autorunToggled(bool checked);
    void quitProgramTriggered();

public slots:
    void setRemoveMemoActionEnabled(bool enabled = true);
    void loadCheckStatesFromDatabase();
    void saveCheckStatesToDatabase();

private slots:
    void verifyRemoveMemo();
    void verifyQuitProgram();

private:
    QAction* createDefaultAction(QString text, void (Actions::*slot)());
    QAction* createControllableAction(QString text, bool* enabled, void (Actions::*slot)());
    QAction* createCheckableAction(QString text, bool* stored_value, void (Actions::*slot)(bool));
    QAction* createDefaultActionWithShortcut(QString text, const QKeySequence& shortcut, void (Actions::*slot)());

private:
    bool m_window_hidden;
    bool m_settings_hidden;
    bool m_remove_memo_enabled;
    bool m_monitor_foreground;
    bool m_autorun;
};

#endif // ACTIONS_H