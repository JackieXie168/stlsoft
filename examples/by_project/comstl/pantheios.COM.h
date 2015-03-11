

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Fri Jan 05 07:27:26 2007
 */
/* Compiler settings for ..\.\pantheios.COM.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __pantheios2ECOM_h__
#define __pantheios2ECOM_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISeverityLevels_FWD_DEFINED__
#define __ISeverityLevels_FWD_DEFINED__
typedef interface ISeverityLevels ISeverityLevels;
#endif 	/* __ISeverityLevels_FWD_DEFINED__ */


#ifndef __ILogFilter_FWD_DEFINED__
#define __ILogFilter_FWD_DEFINED__
typedef interface ILogFilter ILogFilter;
#endif 	/* __ILogFilter_FWD_DEFINED__ */


#ifndef __IStockFilters_FWD_DEFINED__
#define __IStockFilters_FWD_DEFINED__
typedef interface IStockFilters IStockFilters;
#endif 	/* __IStockFilters_FWD_DEFINED__ */


#ifndef __ILoggerManager_FWD_DEFINED__
#define __ILoggerManager_FWD_DEFINED__
typedef interface ILoggerManager ILoggerManager;
#endif 	/* __ILoggerManager_FWD_DEFINED__ */


#ifndef __IEventSourceRegistrar_FWD_DEFINED__
#define __IEventSourceRegistrar_FWD_DEFINED__
typedef interface IEventSourceRegistrar IEventSourceRegistrar;
#endif 	/* __IEventSourceRegistrar_FWD_DEFINED__ */


#ifndef __ILoggerManagerMultibyte_FWD_DEFINED__
#define __ILoggerManagerMultibyte_FWD_DEFINED__
typedef interface ILoggerManagerMultibyte ILoggerManagerMultibyte;
#endif 	/* __ILoggerManagerMultibyte_FWD_DEFINED__ */


#ifndef __ILogger_FWD_DEFINED__
#define __ILogger_FWD_DEFINED__
typedef interface ILogger ILogger;
#endif 	/* __ILogger_FWD_DEFINED__ */


#ifndef __ILoggerMultibyte_FWD_DEFINED__
#define __ILoggerMultibyte_FWD_DEFINED__
typedef interface ILoggerMultibyte ILoggerMultibyte;
#endif 	/* __ILoggerMultibyte_FWD_DEFINED__ */


#ifndef __IInitLogger_FWD_DEFINED__
#define __IInitLogger_FWD_DEFINED__
typedef interface IInitLogger IInitLogger;
#endif 	/* __IInitLogger_FWD_DEFINED__ */


#ifndef __ICompositeLogger_FWD_DEFINED__
#define __ICompositeLogger_FWD_DEFINED__
typedef interface ICompositeLogger ICompositeLogger;
#endif 	/* __ICompositeLogger_FWD_DEFINED__ */


#ifndef __ICompositeLoggerMultibyte_FWD_DEFINED__
#define __ICompositeLoggerMultibyte_FWD_DEFINED__
typedef interface ICompositeLoggerMultibyte ICompositeLoggerMultibyte;
#endif 	/* __ICompositeLoggerMultibyte_FWD_DEFINED__ */


#ifndef __IDocumenter_FWD_DEFINED__
#define __IDocumenter_FWD_DEFINED__
typedef interface IDocumenter IDocumenter;
#endif 	/* __IDocumenter_FWD_DEFINED__ */


#ifndef __IEventSourceRegistrar_FWD_DEFINED__
#define __IEventSourceRegistrar_FWD_DEFINED__
typedef interface IEventSourceRegistrar IEventSourceRegistrar;
#endif 	/* __IEventSourceRegistrar_FWD_DEFINED__ */


#ifndef __ILogger_FWD_DEFINED__
#define __ILogger_FWD_DEFINED__
typedef interface ILogger ILogger;
#endif 	/* __ILogger_FWD_DEFINED__ */


#ifndef __ICompositeLogger_FWD_DEFINED__
#define __ICompositeLogger_FWD_DEFINED__
typedef interface ICompositeLogger ICompositeLogger;
#endif 	/* __ICompositeLogger_FWD_DEFINED__ */


#ifndef __ISeverityLevels_FWD_DEFINED__
#define __ISeverityLevels_FWD_DEFINED__
typedef interface ISeverityLevels ISeverityLevels;
#endif 	/* __ISeverityLevels_FWD_DEFINED__ */


#ifndef __ILoggerManager_FWD_DEFINED__
#define __ILoggerManager_FWD_DEFINED__
typedef interface ILoggerManager ILoggerManager;
#endif 	/* __ILoggerManager_FWD_DEFINED__ */


#ifndef __ILogFilter_FWD_DEFINED__
#define __ILogFilter_FWD_DEFINED__
typedef interface ILogFilter ILogFilter;
#endif 	/* __ILogFilter_FWD_DEFINED__ */


#ifndef __IDocumenter_FWD_DEFINED__
#define __IDocumenter_FWD_DEFINED__
typedef interface IDocumenter IDocumenter;
#endif 	/* __IDocumenter_FWD_DEFINED__ */


#ifndef __ILoggerMultibyte_FWD_DEFINED__
#define __ILoggerMultibyte_FWD_DEFINED__
typedef interface ILoggerMultibyte ILoggerMultibyte;
#endif 	/* __ILoggerMultibyte_FWD_DEFINED__ */


#ifndef __ICompositeLoggerMultibyte_FWD_DEFINED__
#define __ICompositeLoggerMultibyte_FWD_DEFINED__
typedef interface ICompositeLoggerMultibyte ICompositeLoggerMultibyte;
#endif 	/* __ICompositeLoggerMultibyte_FWD_DEFINED__ */


#ifndef __ILoggerManagerMultibyte_FWD_DEFINED__
#define __ILoggerManagerMultibyte_FWD_DEFINED__
typedef interface ILoggerManagerMultibyte ILoggerManagerMultibyte;
#endif 	/* __ILoggerManagerMultibyte_FWD_DEFINED__ */


#ifndef __SeverityLevels_FWD_DEFINED__
#define __SeverityLevels_FWD_DEFINED__

#ifdef __cplusplus
typedef class SeverityLevels SeverityLevels;
#else
typedef struct SeverityLevels SeverityLevels;
#endif /* __cplusplus */

#endif 	/* __SeverityLevels_FWD_DEFINED__ */


#ifndef __StockFilters_FWD_DEFINED__
#define __StockFilters_FWD_DEFINED__

#ifdef __cplusplus
typedef class StockFilters StockFilters;
#else
typedef struct StockFilters StockFilters;
#endif /* __cplusplus */

#endif 	/* __StockFilters_FWD_DEFINED__ */


#ifndef __FixedSeverityFilter_FWD_DEFINED__
#define __FixedSeverityFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class FixedSeverityFilter FixedSeverityFilter;
#else
typedef struct FixedSeverityFilter FixedSeverityFilter;
#endif /* __cplusplus */

#endif 	/* __FixedSeverityFilter_FWD_DEFINED__ */


#ifndef __LoggerManager_FWD_DEFINED__
#define __LoggerManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class LoggerManager LoggerManager;
#else
typedef struct LoggerManager LoggerManager;
#endif /* __cplusplus */

#endif 	/* __LoggerManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_pantheios2ECOM_0000 */
/* [local] */ 

#if 1
typedef char const              *ansistr_t;
#else /* ? 1 */
typedef const unsigned char *ansistr_t;

#endif /* 1 */




extern RPC_IF_HANDLE __MIDL_itf_pantheios2ECOM_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_pantheios2ECOM_0000_v0_0_s_ifspec;

#ifndef __ISeverityLevels_INTERFACE_DEFINED__
#define __ISeverityLevels_INTERFACE_DEFINED__

/* interface ISeverityLevels */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISeverityLevels;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("20169EE0-1F5B-456C-B393-91AA9DFBA769")
    ISeverityLevels : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Debug( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Informational( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Notice( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Warning( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Error( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Critical( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Alert( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Emergency( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISeverityLevelsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISeverityLevels * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISeverityLevels * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISeverityLevels * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISeverityLevels * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISeverityLevels * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISeverityLevels * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISeverityLevels * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Debug )( 
            ISeverityLevels * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Informational )( 
            ISeverityLevels * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Notice )( 
            ISeverityLevels * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Warning )( 
            ISeverityLevels * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Error )( 
            ISeverityLevels * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Critical )( 
            ISeverityLevels * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Alert )( 
            ISeverityLevels * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Emergency )( 
            ISeverityLevels * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ISeverityLevelsVtbl;

    interface ISeverityLevels
    {
        CONST_VTBL struct ISeverityLevelsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISeverityLevels_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISeverityLevels_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISeverityLevels_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISeverityLevels_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISeverityLevels_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISeverityLevels_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISeverityLevels_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISeverityLevels_get_Debug(This,pVal)	\
    (This)->lpVtbl -> get_Debug(This,pVal)

#define ISeverityLevels_get_Informational(This,pVal)	\
    (This)->lpVtbl -> get_Informational(This,pVal)

#define ISeverityLevels_get_Notice(This,pVal)	\
    (This)->lpVtbl -> get_Notice(This,pVal)

#define ISeverityLevels_get_Warning(This,pVal)	\
    (This)->lpVtbl -> get_Warning(This,pVal)

#define ISeverityLevels_get_Error(This,pVal)	\
    (This)->lpVtbl -> get_Error(This,pVal)

#define ISeverityLevels_get_Critical(This,pVal)	\
    (This)->lpVtbl -> get_Critical(This,pVal)

#define ISeverityLevels_get_Alert(This,pVal)	\
    (This)->lpVtbl -> get_Alert(This,pVal)

#define ISeverityLevels_get_Emergency(This,pVal)	\
    (This)->lpVtbl -> get_Emergency(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISeverityLevels_get_Debug_Proxy( 
    ISeverityLevels * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISeverityLevels_get_Debug_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISeverityLevels_get_Informational_Proxy( 
    ISeverityLevels * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISeverityLevels_get_Informational_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISeverityLevels_get_Notice_Proxy( 
    ISeverityLevels * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISeverityLevels_get_Notice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISeverityLevels_get_Warning_Proxy( 
    ISeverityLevels * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISeverityLevels_get_Warning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISeverityLevels_get_Error_Proxy( 
    ISeverityLevels * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISeverityLevels_get_Error_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISeverityLevels_get_Critical_Proxy( 
    ISeverityLevels * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISeverityLevels_get_Critical_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISeverityLevels_get_Alert_Proxy( 
    ISeverityLevels * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISeverityLevels_get_Alert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISeverityLevels_get_Emergency_Proxy( 
    ISeverityLevels * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISeverityLevels_get_Emergency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISeverityLevels_INTERFACE_DEFINED__ */


#ifndef __ILogFilter_INTERFACE_DEFINED__
#define __ILogFilter_INTERFACE_DEFINED__

/* interface ILogFilter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILogFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B643936-17C5-4299-90B8-6FD6BB60AC50")
    ILogFilter : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSeverityLogged( 
            /* [in] */ long severityLevel,
            /* [in] */ long backEndId,
            /* [retval][out] */ VARIANT_BOOL *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILogFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILogFilter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILogFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILogFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILogFilter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILogFilter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILogFilter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILogFilter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSeverityLogged )( 
            ILogFilter * This,
            /* [in] */ long severityLevel,
            /* [in] */ long backEndId,
            /* [retval][out] */ VARIANT_BOOL *pResult);
        
        END_INTERFACE
    } ILogFilterVtbl;

    interface ILogFilter
    {
        CONST_VTBL struct ILogFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILogFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILogFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILogFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILogFilter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILogFilter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILogFilter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILogFilter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILogFilter_IsSeverityLogged(This,severityLevel,backEndId,pResult)	\
    (This)->lpVtbl -> IsSeverityLogged(This,severityLevel,backEndId,pResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogFilter_IsSeverityLogged_Proxy( 
    ILogFilter * This,
    /* [in] */ long severityLevel,
    /* [in] */ long backEndId,
    /* [retval][out] */ VARIANT_BOOL *pResult);


void __RPC_STUB ILogFilter_IsSeverityLogged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILogFilter_INTERFACE_DEFINED__ */


#ifndef __IStockFilters_INTERFACE_DEFINED__
#define __IStockFilters_INTERFACE_DEFINED__

/* interface IStockFilters */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IStockFilters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EE415168-8ED8-40d6-8778-F05CD81D3738")
    IStockFilters : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long severityLevel,
            /* [retval][out] */ ILogFilter **filter) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStockFiltersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStockFilters * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStockFilters * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStockFilters * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IStockFilters * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IStockFilters * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IStockFilters * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IStockFilters * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IStockFilters * This,
            /* [in] */ long severityLevel,
            /* [retval][out] */ ILogFilter **filter);
        
        END_INTERFACE
    } IStockFiltersVtbl;

    interface IStockFilters
    {
        CONST_VTBL struct IStockFiltersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStockFilters_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStockFilters_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStockFilters_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStockFilters_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStockFilters_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStockFilters_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStockFilters_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStockFilters_get_Item(This,severityLevel,filter)	\
    (This)->lpVtbl -> get_Item(This,severityLevel,filter)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IStockFilters_get_Item_Proxy( 
    IStockFilters * This,
    /* [in] */ long severityLevel,
    /* [retval][out] */ ILogFilter **filter);


void __RPC_STUB IStockFilters_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStockFilters_INTERFACE_DEFINED__ */


#ifndef __ILoggerManager_INTERFACE_DEFINED__
#define __ILoggerManager_INTERFACE_DEFINED__

/* interface ILoggerManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILoggerManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("736A57A5-4A99-4EBA-BF54-CC02A774220A")
    ILoggerManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLogger( 
            /* [string][in] */ BSTR loggerType,
            /* [string][in] */ BSTR processIdentity,
            /* [defaultvalue][in] */ VARIANT initArguments,
            /* [defaultvalue][in] */ VARIANT filterSpec,
            /* [retval][out] */ ILogger **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KnownLoggerAliases( 
            /* [retval][out] */ LPDISPATCH *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILoggerManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILoggerManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILoggerManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILoggerManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILoggerManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILoggerManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILoggerManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILoggerManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLogger )( 
            ILoggerManager * This,
            /* [string][in] */ BSTR loggerType,
            /* [string][in] */ BSTR processIdentity,
            /* [defaultvalue][in] */ VARIANT initArguments,
            /* [defaultvalue][in] */ VARIANT filterSpec,
            /* [retval][out] */ ILogger **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KnownLoggerAliases )( 
            ILoggerManager * This,
            /* [retval][out] */ LPDISPATCH *pVal);
        
        END_INTERFACE
    } ILoggerManagerVtbl;

    interface ILoggerManager
    {
        CONST_VTBL struct ILoggerManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILoggerManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILoggerManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILoggerManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILoggerManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILoggerManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILoggerManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILoggerManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILoggerManager_GetLogger(This,loggerType,processIdentity,initArguments,filterSpec,pVal)	\
    (This)->lpVtbl -> GetLogger(This,loggerType,processIdentity,initArguments,filterSpec,pVal)

#define ILoggerManager_get_KnownLoggerAliases(This,pVal)	\
    (This)->lpVtbl -> get_KnownLoggerAliases(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILoggerManager_GetLogger_Proxy( 
    ILoggerManager * This,
    /* [string][in] */ BSTR loggerType,
    /* [string][in] */ BSTR processIdentity,
    /* [defaultvalue][in] */ VARIANT initArguments,
    /* [defaultvalue][in] */ VARIANT filterSpec,
    /* [retval][out] */ ILogger **pVal);


void __RPC_STUB ILoggerManager_GetLogger_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ILoggerManager_get_KnownLoggerAliases_Proxy( 
    ILoggerManager * This,
    /* [retval][out] */ LPDISPATCH *pVal);


void __RPC_STUB ILoggerManager_get_KnownLoggerAliases_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILoggerManager_INTERFACE_DEFINED__ */


#ifndef __IEventSourceRegistrar_INTERFACE_DEFINED__
#define __IEventSourceRegistrar_INTERFACE_DEFINED__

/* interface IEventSourceRegistrar */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEventSourceRegistrar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("48717F39-8332-4341-B2B0-A8A20556803F")
    IEventSourceRegistrar : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterEventSource( 
            /* [string][in] */ BSTR sourceName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeregisterEventSource( 
            /* [string][in] */ BSTR sourceName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsEventSourceRegistered( 
            /* [string][in] */ BSTR sourceName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEventSourceRegistrarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEventSourceRegistrar * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEventSourceRegistrar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEventSourceRegistrar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEventSourceRegistrar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEventSourceRegistrar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEventSourceRegistrar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEventSourceRegistrar * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterEventSource )( 
            IEventSourceRegistrar * This,
            /* [string][in] */ BSTR sourceName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeregisterEventSource )( 
            IEventSourceRegistrar * This,
            /* [string][in] */ BSTR sourceName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsEventSourceRegistered )( 
            IEventSourceRegistrar * This,
            /* [string][in] */ BSTR sourceName);
        
        END_INTERFACE
    } IEventSourceRegistrarVtbl;

    interface IEventSourceRegistrar
    {
        CONST_VTBL struct IEventSourceRegistrarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEventSourceRegistrar_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEventSourceRegistrar_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEventSourceRegistrar_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEventSourceRegistrar_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEventSourceRegistrar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEventSourceRegistrar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEventSourceRegistrar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEventSourceRegistrar_RegisterEventSource(This,sourceName)	\
    (This)->lpVtbl -> RegisterEventSource(This,sourceName)

#define IEventSourceRegistrar_DeregisterEventSource(This,sourceName)	\
    (This)->lpVtbl -> DeregisterEventSource(This,sourceName)

#define IEventSourceRegistrar_IsEventSourceRegistered(This,sourceName)	\
    (This)->lpVtbl -> IsEventSourceRegistered(This,sourceName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IEventSourceRegistrar_RegisterEventSource_Proxy( 
    IEventSourceRegistrar * This,
    /* [string][in] */ BSTR sourceName);


void __RPC_STUB IEventSourceRegistrar_RegisterEventSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IEventSourceRegistrar_DeregisterEventSource_Proxy( 
    IEventSourceRegistrar * This,
    /* [string][in] */ BSTR sourceName);


void __RPC_STUB IEventSourceRegistrar_DeregisterEventSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IEventSourceRegistrar_IsEventSourceRegistered_Proxy( 
    IEventSourceRegistrar * This,
    /* [string][in] */ BSTR sourceName);


void __RPC_STUB IEventSourceRegistrar_IsEventSourceRegistered_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEventSourceRegistrar_INTERFACE_DEFINED__ */


#ifndef __ILoggerManagerMultibyte_INTERFACE_DEFINED__
#define __ILoggerManagerMultibyte_INTERFACE_DEFINED__

/* interface ILoggerManagerMultibyte */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILoggerManagerMultibyte;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("375B6E0F-1982-4fbc-A635-F3175CF648CD")
    ILoggerManagerMultibyte : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLoggerMultibyte( 
            /* [string][in] */ ansistr_t loggerClass,
            /* [string][in] */ ansistr_t processIdentity,
            /* [in] */ VARIANT initArguments,
            /* [defaultvalue][in] */ VARIANT filterSpec,
            /* [retval][out] */ ILoggerMultibyte **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILoggerManagerMultibyteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILoggerManagerMultibyte * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILoggerManagerMultibyte * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILoggerManagerMultibyte * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLoggerMultibyte )( 
            ILoggerManagerMultibyte * This,
            /* [string][in] */ ansistr_t loggerClass,
            /* [string][in] */ ansistr_t processIdentity,
            /* [in] */ VARIANT initArguments,
            /* [defaultvalue][in] */ VARIANT filterSpec,
            /* [retval][out] */ ILoggerMultibyte **pVal);
        
        END_INTERFACE
    } ILoggerManagerMultibyteVtbl;

    interface ILoggerManagerMultibyte
    {
        CONST_VTBL struct ILoggerManagerMultibyteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILoggerManagerMultibyte_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILoggerManagerMultibyte_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILoggerManagerMultibyte_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILoggerManagerMultibyte_GetLoggerMultibyte(This,loggerClass,processIdentity,initArguments,filterSpec,pVal)	\
    (This)->lpVtbl -> GetLoggerMultibyte(This,loggerClass,processIdentity,initArguments,filterSpec,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILoggerManagerMultibyte_GetLoggerMultibyte_Proxy( 
    ILoggerManagerMultibyte * This,
    /* [string][in] */ ansistr_t loggerClass,
    /* [string][in] */ ansistr_t processIdentity,
    /* [in] */ VARIANT initArguments,
    /* [defaultvalue][in] */ VARIANT filterSpec,
    /* [retval][out] */ ILoggerMultibyte **pVal);


void __RPC_STUB ILoggerManagerMultibyte_GetLoggerMultibyte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILoggerManagerMultibyte_INTERFACE_DEFINED__ */


#ifndef __ILogger_INTERFACE_DEFINED__
#define __ILogger_INTERFACE_DEFINED__

/* interface ILogger */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILogger;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0C573304-FDC4-4274-A417-B449C8DF5ABC")
    ILogger : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProcessIdentity( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackEndId( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Log( 
            /* [in] */ long severity,
            /* [in] */ SAFEARRAY * arguments) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Log_DEBUG( 
            /* [in] */ SAFEARRAY * arguments) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Log_INFORMATIONAL( 
            /* [in] */ SAFEARRAY * arguments) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Log_NOTICE( 
            /* [in] */ SAFEARRAY * arguments) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Log_WARNING( 
            /* [in] */ SAFEARRAY * arguments) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Log_ERROR( 
            /* [in] */ SAFEARRAY * arguments) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Log_CRITICAL( 
            /* [in] */ SAFEARRAY * arguments) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Log_ALERT( 
            /* [in] */ SAFEARRAY * arguments) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Log_EMERGENCY( 
            /* [in] */ SAFEARRAY * arguments) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILoggerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILogger * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILogger * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILogger * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILogger * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILogger * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILogger * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILogger * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProcessIdentity )( 
            ILogger * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackEndId )( 
            ILogger * This,
            /* [retval][out] */ long *pVal);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Log )( 
            ILogger * This,
            /* [in] */ long severity,
            /* [in] */ SAFEARRAY * arguments);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Log_DEBUG )( 
            ILogger * This,
            /* [in] */ SAFEARRAY * arguments);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Log_INFORMATIONAL )( 
            ILogger * This,
            /* [in] */ SAFEARRAY * arguments);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Log_NOTICE )( 
            ILogger * This,
            /* [in] */ SAFEARRAY * arguments);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Log_WARNING )( 
            ILogger * This,
            /* [in] */ SAFEARRAY * arguments);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Log_ERROR )( 
            ILogger * This,
            /* [in] */ SAFEARRAY * arguments);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Log_CRITICAL )( 
            ILogger * This,
            /* [in] */ SAFEARRAY * arguments);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Log_ALERT )( 
            ILogger * This,
            /* [in] */ SAFEARRAY * arguments);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Log_EMERGENCY )( 
            ILogger * This,
            /* [in] */ SAFEARRAY * arguments);
        
        END_INTERFACE
    } ILoggerVtbl;

    interface ILogger
    {
        CONST_VTBL struct ILoggerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILogger_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILogger_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILogger_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILogger_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILogger_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILogger_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILogger_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILogger_get_ProcessIdentity(This,pVal)	\
    (This)->lpVtbl -> get_ProcessIdentity(This,pVal)

#define ILogger_get_BackEndId(This,pVal)	\
    (This)->lpVtbl -> get_BackEndId(This,pVal)

#define ILogger_Log(This,severity,arguments)	\
    (This)->lpVtbl -> Log(This,severity,arguments)

#define ILogger_Log_DEBUG(This,arguments)	\
    (This)->lpVtbl -> Log_DEBUG(This,arguments)

#define ILogger_Log_INFORMATIONAL(This,arguments)	\
    (This)->lpVtbl -> Log_INFORMATIONAL(This,arguments)

#define ILogger_Log_NOTICE(This,arguments)	\
    (This)->lpVtbl -> Log_NOTICE(This,arguments)

#define ILogger_Log_WARNING(This,arguments)	\
    (This)->lpVtbl -> Log_WARNING(This,arguments)

#define ILogger_Log_ERROR(This,arguments)	\
    (This)->lpVtbl -> Log_ERROR(This,arguments)

#define ILogger_Log_CRITICAL(This,arguments)	\
    (This)->lpVtbl -> Log_CRITICAL(This,arguments)

#define ILogger_Log_ALERT(This,arguments)	\
    (This)->lpVtbl -> Log_ALERT(This,arguments)

#define ILogger_Log_EMERGENCY(This,arguments)	\
    (This)->lpVtbl -> Log_EMERGENCY(This,arguments)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ILogger_get_ProcessIdentity_Proxy( 
    ILogger * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ILogger_get_ProcessIdentity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ILogger_get_BackEndId_Proxy( 
    ILogger * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ILogger_get_BackEndId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogger_Log_Proxy( 
    ILogger * This,
    /* [in] */ long severity,
    /* [in] */ SAFEARRAY * arguments);


void __RPC_STUB ILogger_Log_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogger_Log_DEBUG_Proxy( 
    ILogger * This,
    /* [in] */ SAFEARRAY * arguments);


void __RPC_STUB ILogger_Log_DEBUG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogger_Log_INFORMATIONAL_Proxy( 
    ILogger * This,
    /* [in] */ SAFEARRAY * arguments);


void __RPC_STUB ILogger_Log_INFORMATIONAL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogger_Log_NOTICE_Proxy( 
    ILogger * This,
    /* [in] */ SAFEARRAY * arguments);


void __RPC_STUB ILogger_Log_NOTICE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogger_Log_WARNING_Proxy( 
    ILogger * This,
    /* [in] */ SAFEARRAY * arguments);


void __RPC_STUB ILogger_Log_WARNING_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogger_Log_ERROR_Proxy( 
    ILogger * This,
    /* [in] */ SAFEARRAY * arguments);


void __RPC_STUB ILogger_Log_ERROR_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogger_Log_CRITICAL_Proxy( 
    ILogger * This,
    /* [in] */ SAFEARRAY * arguments);


void __RPC_STUB ILogger_Log_CRITICAL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogger_Log_ALERT_Proxy( 
    ILogger * This,
    /* [in] */ SAFEARRAY * arguments);


void __RPC_STUB ILogger_Log_ALERT_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE ILogger_Log_EMERGENCY_Proxy( 
    ILogger * This,
    /* [in] */ SAFEARRAY * arguments);


void __RPC_STUB ILogger_Log_EMERGENCY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILogger_INTERFACE_DEFINED__ */


#ifndef __ILoggerMultibyte_INTERFACE_DEFINED__
#define __ILoggerMultibyte_INTERFACE_DEFINED__

/* interface ILoggerMultibyte */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILoggerMultibyte;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("417DC45C-F1E2-415d-9636-A68456272ACB")
    ILoggerMultibyte : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LogMultibyte( 
            /* [in] */ long severity,
            /* [string][in] */ ansistr_t message,
            /* [defaultvalue][in] */ long cchMessage = -1) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILoggerMultibyteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILoggerMultibyte * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILoggerMultibyte * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILoggerMultibyte * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *LogMultibyte )( 
            ILoggerMultibyte * This,
            /* [in] */ long severity,
            /* [string][in] */ ansistr_t message,
            /* [defaultvalue][in] */ long cchMessage);
        
        END_INTERFACE
    } ILoggerMultibyteVtbl;

    interface ILoggerMultibyte
    {
        CONST_VTBL struct ILoggerMultibyteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILoggerMultibyte_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILoggerMultibyte_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILoggerMultibyte_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILoggerMultibyte_LogMultibyte(This,severity,message,cchMessage)	\
    (This)->lpVtbl -> LogMultibyte(This,severity,message,cchMessage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILoggerMultibyte_LogMultibyte_Proxy( 
    ILoggerMultibyte * This,
    /* [in] */ long severity,
    /* [string][in] */ ansistr_t message,
    /* [defaultvalue][in] */ long cchMessage);


void __RPC_STUB ILoggerMultibyte_LogMultibyte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILoggerMultibyte_INTERFACE_DEFINED__ */


#ifndef __IInitLogger_INTERFACE_DEFINED__
#define __IInitLogger_INTERFACE_DEFINED__

/* interface IInitLogger */
/* [restricted][hidden][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IInitLogger;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E7569736-83EC-4196-99AA-E227FFB09DB1")
    IInitLogger : public IUnknown
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [string][in] */ const OLECHAR *processIdentity,
            /* [in] */ ILogFilter *filter,
            /* [in] */ long backEndId,
            /* [in] */ VARIANT getLoggerArgs,
            /* [in] */ VARIANT reserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInitLoggerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInitLogger * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInitLogger * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInitLogger * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IInitLogger * This,
            /* [string][in] */ const OLECHAR *processIdentity,
            /* [in] */ ILogFilter *filter,
            /* [in] */ long backEndId,
            /* [in] */ VARIANT getLoggerArgs,
            /* [in] */ VARIANT reserved);
        
        END_INTERFACE
    } IInitLoggerVtbl;

    interface IInitLogger
    {
        CONST_VTBL struct IInitLoggerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInitLogger_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInitLogger_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInitLogger_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInitLogger_Init(This,processIdentity,filter,backEndId,getLoggerArgs,reserved)	\
    (This)->lpVtbl -> Init(This,processIdentity,filter,backEndId,getLoggerArgs,reserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IInitLogger_Init_Proxy( 
    IInitLogger * This,
    /* [string][in] */ const OLECHAR *processIdentity,
    /* [in] */ ILogFilter *filter,
    /* [in] */ long backEndId,
    /* [in] */ VARIANT getLoggerArgs,
    /* [in] */ VARIANT reserved);


void __RPC_STUB IInitLogger_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IInitLogger_INTERFACE_DEFINED__ */


#ifndef __ICompositeLogger_INTERFACE_DEFINED__
#define __ICompositeLogger_INTERFACE_DEFINED__

/* interface ICompositeLogger */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICompositeLogger;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("46BE772A-0A2C-49b0-8296-A12E92E48D8C")
    ICompositeLogger : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Chain( 
            /* [in] */ ILogger *logger,
            /* [defaultvalue][in] */ long severityCeiling = -1) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unchain( 
            /* [in] */ ILogger *logger) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsChained( 
            /* [in] */ ILogger *logger,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICompositeLoggerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICompositeLogger * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICompositeLogger * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICompositeLogger * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICompositeLogger * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICompositeLogger * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICompositeLogger * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICompositeLogger * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Chain )( 
            ICompositeLogger * This,
            /* [in] */ ILogger *logger,
            /* [defaultvalue][in] */ long severityCeiling);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Unchain )( 
            ICompositeLogger * This,
            /* [in] */ ILogger *logger);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsChained )( 
            ICompositeLogger * This,
            /* [in] */ ILogger *logger,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } ICompositeLoggerVtbl;

    interface ICompositeLogger
    {
        CONST_VTBL struct ICompositeLoggerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICompositeLogger_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICompositeLogger_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICompositeLogger_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICompositeLogger_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICompositeLogger_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICompositeLogger_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICompositeLogger_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICompositeLogger_Chain(This,logger,severityCeiling)	\
    (This)->lpVtbl -> Chain(This,logger,severityCeiling)

#define ICompositeLogger_Unchain(This,logger)	\
    (This)->lpVtbl -> Unchain(This,logger)

#define ICompositeLogger_IsChained(This,logger,pVal)	\
    (This)->lpVtbl -> IsChained(This,logger,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICompositeLogger_Chain_Proxy( 
    ICompositeLogger * This,
    /* [in] */ ILogger *logger,
    /* [defaultvalue][in] */ long severityCeiling);


void __RPC_STUB ICompositeLogger_Chain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICompositeLogger_Unchain_Proxy( 
    ICompositeLogger * This,
    /* [in] */ ILogger *logger);


void __RPC_STUB ICompositeLogger_Unchain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICompositeLogger_IsChained_Proxy( 
    ICompositeLogger * This,
    /* [in] */ ILogger *logger,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ICompositeLogger_IsChained_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICompositeLogger_INTERFACE_DEFINED__ */


#ifndef __ICompositeLoggerMultibyte_INTERFACE_DEFINED__
#define __ICompositeLoggerMultibyte_INTERFACE_DEFINED__

/* interface ICompositeLoggerMultibyte */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICompositeLoggerMultibyte;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A943E1E-01CC-4e58-B1C8-243A1BD6D6B1")
    ICompositeLoggerMultibyte : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ChainNamedMultibyte( 
            /* [string][in] */ ansistr_t loggerClass,
            /* [string][in] */ ansistr_t initArguments,
            /* [in] */ IUnknown *manager,
            /* [defaultvalue][in] */ long severityCeiling = -1) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICompositeLoggerMultibyteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICompositeLoggerMultibyte * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICompositeLoggerMultibyte * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICompositeLoggerMultibyte * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ChainNamedMultibyte )( 
            ICompositeLoggerMultibyte * This,
            /* [string][in] */ ansistr_t loggerClass,
            /* [string][in] */ ansistr_t initArguments,
            /* [in] */ IUnknown *manager,
            /* [defaultvalue][in] */ long severityCeiling);
        
        END_INTERFACE
    } ICompositeLoggerMultibyteVtbl;

    interface ICompositeLoggerMultibyte
    {
        CONST_VTBL struct ICompositeLoggerMultibyteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICompositeLoggerMultibyte_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICompositeLoggerMultibyte_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICompositeLoggerMultibyte_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICompositeLoggerMultibyte_ChainNamedMultibyte(This,loggerClass,initArguments,manager,severityCeiling)	\
    (This)->lpVtbl -> ChainNamedMultibyte(This,loggerClass,initArguments,manager,severityCeiling)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICompositeLoggerMultibyte_ChainNamedMultibyte_Proxy( 
    ICompositeLoggerMultibyte * This,
    /* [string][in] */ ansistr_t loggerClass,
    /* [string][in] */ ansistr_t initArguments,
    /* [in] */ IUnknown *manager,
    /* [defaultvalue][in] */ long severityCeiling);


void __RPC_STUB ICompositeLoggerMultibyte_ChainNamedMultibyte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICompositeLoggerMultibyte_INTERFACE_DEFINED__ */


#ifndef __IDocumenter_INTERFACE_DEFINED__
#define __IDocumenter_INTERFACE_DEFINED__

/* interface IDocumenter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDocumenter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D0EE8EEE-FF64-4096-BB23-06664E8F9E26")
    IDocumenter : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DocString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDocumenterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDocumenter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDocumenter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDocumenter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDocumenter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDocumenter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDocumenter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDocumenter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DocString )( 
            IDocumenter * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IDocumenterVtbl;

    interface IDocumenter
    {
        CONST_VTBL struct IDocumenterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDocumenter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDocumenter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDocumenter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDocumenter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDocumenter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDocumenter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDocumenter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDocumenter_get_DocString(This,pVal)	\
    (This)->lpVtbl -> get_DocString(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IDocumenter_get_DocString_Proxy( 
    IDocumenter * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IDocumenter_get_DocString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDocumenter_INTERFACE_DEFINED__ */



#ifndef __PANTHEIOS_COMLib_LIBRARY_DEFINED__
#define __PANTHEIOS_COMLib_LIBRARY_DEFINED__

/* library PANTHEIOS_COMLib */
/* [helpstring][version][uuid] */ 












#define PANTHEIOS_COM_LOGGER_CLSIDS_ARE_HIDDEN

EXTERN_C const CLSID CLSID__CompositeLogger;

#ifdef __cplusplus

class DECLSPEC_UUID("60A47363-7828-4428-B33A-0759B859B9C8")
_CompositeLogger;
#endif

EXTERN_C const CLSID CLSID__ConsoleLogger;

#ifdef __cplusplus

class DECLSPEC_UUID("7EBDEBB3-EEC6-41ab-A309-FA5FB99A698D")
_ConsoleLogger;
#endif

EXTERN_C const CLSID CLSID__DebugLogger;

#ifdef __cplusplus

class DECLSPEC_UUID("83D42E7B-6A62-4BA3-9FA2-5EB07F1FC30F")
_DebugLogger;
#endif

EXTERN_C const CLSID CLSID__ErrorObjectLogger;

#ifdef __cplusplus

class DECLSPEC_UUID("CBC59667-4D1B-4DA4-B6C9-44C1CA77D491")
_ErrorObjectLogger;
#endif

EXTERN_C const CLSID CLSID__EventLogLogger;

#ifdef __cplusplus

class DECLSPEC_UUID("EBF66B63-63CF-45CF-BFD6-BCE60EE61EF1")
_EventLogLogger;
#endif

EXTERN_C const CLSID CLSID__FileLogger;

#ifdef __cplusplus

class DECLSPEC_UUID("B81F4172-0301-45ac-83B2-C73E35C1DD63")
_FileLogger;
#endif

EXTERN_C const CLSID CLSID__NullLogger;

#ifdef __cplusplus

class DECLSPEC_UUID("21D26DA6-CA61-4a08-84BD-537A6EEE26A8")
_NullLogger;
#endif

EXTERN_C const CLSID CLSID__SysLogLogger;

#ifdef __cplusplus

class DECLSPEC_UUID("22053C94-E50A-4D31-9DC2-BBFBF671E1A8")
_SysLogLogger;
#endif


EXTERN_C const IID LIBID_PANTHEIOS_COMLib;

EXTERN_C const CLSID CLSID_SeverityLevels;

#ifdef __cplusplus

class DECLSPEC_UUID("92B2FCBD-75BB-4411-AF84-2DC8A4F4F16B")
SeverityLevels;
#endif

EXTERN_C const CLSID CLSID_StockFilters;

#ifdef __cplusplus

class DECLSPEC_UUID("650EDE6C-3E2F-4F8B-A425-F1853FBC789D")
StockFilters;
#endif

EXTERN_C const CLSID CLSID_FixedSeverityFilter;

#ifdef __cplusplus

class DECLSPEC_UUID("F0816D05-80E2-4A14-B2AC-47B4840AC319")
FixedSeverityFilter;
#endif

EXTERN_C const CLSID CLSID_LoggerManager;

#ifdef __cplusplus

class DECLSPEC_UUID("4E7D5C47-8F96-45DE-905D-AA3E9E592DE3")
LoggerManager;
#endif
#endif /* __PANTHEIOS_COMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


