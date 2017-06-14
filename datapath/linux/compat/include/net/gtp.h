#ifndef __NET_GTP_WRAPPER_H
#define __NET_GTP_WRAPPER_H  1

#ifdef CONFIG_INET
#include <net/udp_tunnel.h>
#endif /* ifdef CONFIG_INET */

#ifdef USE_UPSTREAM_TUNNEL
#include_next <net/gtp.h>

static inline int rpl_gtp_init_module(void)
{
	return 0;
}
static inline void rpl_gtp_cleanup_module(void)
{}

#define gtp_xmit dev_queue_xmit

#ifdef CONFIG_INET
#ifndef HAVE_NAME_ASSIGN_TYPE
static inline struct net_device *rpl_gtp_dev_create_fb(
	struct net *net, const char *name, u8 name_assign_type, u16 dst_port) {
	return gtp_dev_create_fb(net, name, dst_port);
}
#define gtp_create_flow_based_dev rpl_gtp_dev_create_fb
#endif
#endif

#endif /* USE_UPSTREAM_TUNNEL */

#define gtp_init_module rpl_gtp_init_module
#define gtp_cleanup_module rpl_gtp_cleanup_module

#endif /* __NET_GTP_WRAPPER_H */
