#pragma once

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QLCDNumber>
#include <QTimer>
#include "flut/timer.hpp"
#include "flut/math/delta.hpp"

class QAbstractButton;
class QAbstractSlider;
class QComboBox;

class QPlayControl : public QWidget
{
	Q_OBJECT

public:
	QPlayControl( QWidget *parent = 0 );
	double slowMotionFactor() const { return slomoFactor; }

	void setRange( double min, double max );
	void setTime( double time );
	bool getLoop();
	bool getAutoExtendRange() { return autoExtendRange;  }

public slots:
	void setLoop( bool b );
	void setAutoExtendRange( bool b ) { autoExtendRange = b; }
	void play();
	void stop();
	void reset();
	void previous();
	void next();

signals:
	void playTriggered();
	void stopTriggered();
	void resetTriggered();
	void nextTriggered();
	void previousTriggered();
	void slowMotionChanged( int i );
	void timeChanged( double time );
	void sliderChanged( int );

private slots:
	void updateSlowMotion( int );
	void updateSlider( int );
	void timeout();

private:
	QAbstractButton *playButton;
	QAbstractButton *stopButton;
	QAbstractButton *nextButton;
	QAbstractButton *previousButton;
	QAbstractButton *loopButton;
	QComboBox *slowMotionBox;
	QSlider *slider;
	QLCDNumber* label;
	double currentTime;
	double skipTime;
	double slomoFactor;
	double minTime, maxTime;

	bool autoExtendRange;

	QTimer qtimer;
	flut::timer timer;
	flut::delta< flut::timer::seconds_t > timer_delta;
};