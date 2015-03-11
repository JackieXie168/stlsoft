/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/synch/checkout_token.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Synchronisation
 *              library's .
 *
 * Created:     9th June 2006
 * Updated:     15th September 2006
 *
 * www:         http://www.stlsoft.org/
 *
 * License:     Copyright (c) 2006, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              (Licensed under the Synesis Software Open License)
 *
 *              This source code is placed into the public domain 2006
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* STLSoft Header Files */
#include <stlsoft/synch/checkout_token.hpp>
#include <stlsoft/conversion/sap_cast.hpp>

/* PlatformSTL Header Files */
#include <platformstl/synch/thread_mutex.hpp>

/* PThreads Header Files */
#include <pthread.h>
#include <sched.h>

/* Standard C++ Header Files */
#include <exception>
#include <queue>
#include <deque>

/* Standard C Header Files */
#include <stdio.h>	// for fprintf(), which we must use, because the iostreams are not atomic
#include <stdlib.h> // for EXIT_FAILURE, EXIT_SUCCESS

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

class QueueSet
{
public: // Member Types
    typedef std::queue<int>                                     queue_type;
    typedef QueueSet                                            class_type;
private:
    typedef platformstl::thread_mutex                           mutex_type;
public:
    typedef stlsoft::checkout_token<mutex_type, queue_type&>    queue_token_type;

public: // Construction
    QueueSet();
    ~QueueSet();

public:
	queue_token_type	queue1();
	queue_token_type	queue2();

	void				set_complete();
	bool				is_complete() const;

private:
	bool			m_bComplete;
    mutex_type      m_mx1;
    queue_type      m_queue1;
    mutex_type      m_mx2;
    queue_type      m_queue2;
};

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void *writer_proc(void *);
static void *reader_proc(void *);

/* ////////////////////////////////////////////////////////////////////// */

int main()
{
    QueueSet    queues;
    pthread_t   writerThread;
    pthread_t   readerThread;
    int         err;
	pthread_t	selfThread	=	pthread_self();
	void		*writerResult;
	void		*readerResult;

	::srand(*stlsoft::sap_cast<unsigned const*>(&selfThread));

    if(0 != (err = pthread_create(&writerThread, NULL, writer_proc, &queues)))
    {
        fprintf(stderr, "Failed to create writer thread: %s\n", strerror(err));

        return EXIT_FAILURE;
    }
    if(0 != (err = pthread_create(&readerThread, NULL, reader_proc, &queues)))
    {
        fprintf(stderr, "Failed to create reader thread: %s\n", strerror(err));

        return EXIT_FAILURE;
    }

    if(0 != (err = pthread_join(writerThread, &writerResult)))
    {
        fprintf(stderr, "Failed to join writer thread: %s\n", strerror(err));

        return EXIT_FAILURE;
    }
    if(0 != (err = pthread_join(readerThread, &readerResult)))
    {
        fprintf(stderr, "Failed to join reader thread: %s\n", strerror(err));

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////// */

static void *writer_proc(void *args)
{
	QueueSet	&queues	=	*static_cast<QueueSet*>(args);
	size_t		total	=	0;

	{ for(size_t i = 0; i < 1000; ++i)
	{
		{ // Scope the access and locking of queue #1
			QueueSet::queue_token_type	q	=	queues.queue1();
			const size_t				n	=	1 + ::rand() % 1000;

			{ for(size_t j = 0; j < n; ++j, ++total)
			{
				q.member().push(j);
			}}
		} // End of scope: unlocks queue #1

		{ // Scope the access and locking of queue #2
			QueueSet::queue_token_type	q	=	queues.queue2();
			const size_t				n	=	1 + ::rand() % 1000;

			{ for(size_t j = 0; j < n; ++j, ++total)
			{
				q.member().push(j);
			}}
		} // End of scope: unlocks queue #2
	}}

	queues.set_complete();

	fprintf(stdout, "Writer enqueued %lu items\n", total);

	return NULL;
}

static void *reader_proc(void *args)
{
	QueueSet	&queues	=	*static_cast<QueueSet*>(args);
	size_t		total	=	0;

	{ for(;;)
	{
		size_t	current	=	0;

		{ // Scope the access and locking of queue #1
			QueueSet::queue_token_type	q	=	queues.queue1();
			const size_t				n	=	1 + ::rand() % 100;

#ifdef _DEBUG
			cout << "Reading from queue 1:" << endl;
#endif /* _DEBUG */
			{ for(size_t i = 0; i < n && !q.member().empty(); ++i, ++total, ++current)
			{
				int	top	=	q.member().front();

				q.member().pop();

#ifdef _DEBUG
				cout << top << endl;
#endif /* _DEBUG */
			}}
		} // End of scope: unlocks queue #1

		{ // Scope the access and locking of queue #2
			QueueSet::queue_token_type	q	=	queues.queue2();
			const size_t				n	=	1 + ::rand() % 100;

#ifdef _DEBUG
			cout << "Reading from queue 2:" << endl;
#endif /* _DEBUG */
			{ for(size_t i = 0; i < n && !q.member().empty(); ++i, ++total, ++current)
			{
				int	top	=	q.member().front();

				q.member().pop();

#ifdef _DEBUG
				cout << top << endl;
#endif /* _DEBUG */
			}}
		} // End of scope: unlocks queue #2

		if( 0 == current &&
			queues.is_complete())
		{
			break;
		}
	}}

	fprintf(stdout, "Reader dequeued %lu items\n", total);

	return NULL;
}

/* ////////////////////////////////////////////////////////////////////// */

QueueSet::QueueSet()
	: m_bComplete(false)
	, m_mx1()
	, m_queue1()
    , m_mx2()
    , m_queue2()
{}

QueueSet::~QueueSet()
{}

QueueSet::queue_token_type QueueSet::queue1()
{
	return queue_token_type(m_mx1, m_queue1);
}

QueueSet::queue_token_type QueueSet::queue2()
{
	return queue_token_type(m_mx2, m_queue2);
}

void QueueSet::set_complete()
{
	m_bComplete = true;
}

bool QueueSet::is_complete() const
{
	return m_bComplete;
}

/* ////////////////////////////////////////////////////////////////////// */
