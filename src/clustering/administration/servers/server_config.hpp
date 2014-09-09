// Copyright 2010-2014 RethinkDB, all rights reserved.
#ifndef CLUSTERING_ADMINISTRATION_SERVERS_SERVER_CONFIG_HPP_
#define CLUSTERING_ADMINISTRATION_SERVERS_SERVER_CONFIG_HPP_

#include <string>
#include <vector>

#include "errors.hpp"
#include <boost/shared_ptr.hpp>

#include "clustering/administration/servers/server_common.hpp"
#include "clustering/administration/servers/machine_metadata.hpp"
#include "rdb_protocol/artificial_table/backend.hpp"
#include "rpc/semilattice/view.hpp"

class server_name_client_t;

class server_config_artificial_table_backend_t :
    public common_server_artificial_table_backend_t
{
public:
    server_config_artificial_table_backend_t(
            boost::shared_ptr< semilattice_read_view_t<
                machines_semilattice_metadata_t> > _servers_sl_view,
            server_name_client_t *_name_client) :
        common_server_artificial_table_backend_t(_servers_sl_view, _name_client) { }

    bool read_row(
            ql::datum_t primary_key,
            signal_t *interruptor,
            ql::datum_t *row_out,
            std::string *error_out);
    bool write_row(
            ql::datum_t primary_key,
            ql::datum_t new_value,
            signal_t *interruptor,
            std::string *error_out);
};

#endif /* CLUSTERING_ADMINISTRATION_SERVERS_SERVER_CONFIG_HPP_ */
