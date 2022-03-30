import * as React from 'react';
import { ChangeEvent, useState, useEffect } from 'react';
import PropTypes from 'prop-types';
import {
  Tooltip,
  Box,
  Card,
  IconButton,
  Table,
  TableBody,
  TableCell,
  TableHead,
  TablePagination,
  TableRow,
  TableContainer,
  Typography,
  useTheme,
  Button,
  Grid,
  TextField,
} from '@mui/material';
import Modal from '@mui/material/Modal';
import { Client, ClientStatus } from 'src/models/client';
import EditTwoToneIcon from '@mui/icons-material/EditTwoTone';
import DeleteTwoToneIcon from '@mui/icons-material/DeleteTwoTone';
import ArticleTwoToneIcon from '@mui/icons-material/ArticleTwoTone';
import KeyboardReturnTwoToneIcon from '@mui/icons-material/KeyboardReturn';
import SearchTwoToneIcon from '@mui/icons-material/Search';
import { NavLink } from 'react-router-dom';
import { remove, findAll, findSearch } from 'src/services/client';

interface Filters {
  status?: ClientStatus;
}

// const getStatusLabel = (clientStatus: ClientStatus): JSX.Element => {
//   const map = {
//     active: {
//       text: 'Ativo',
//       color: 'success',
//     },
//     inactive: {
//       text: 'Inativo',
//       color: 'error',
//     },
//   };

//   const { text, color }: any = map[clientStatus];

//   return <Label color={color}>{text}</Label>;
// };

const style = {
  position: 'absolute' as 'absolute',
  top: '50%',
  left: '50%',
  transform: 'translate(-50%, -50%)',
  width: 400,
  height: 150,
  bgcolor: 'background.paper',
  border: '2px solid #000',
  boxShadow: 24,
  p: 4,
  textAlign: 'center',
};

const applyFilters = (clients: Client[], filters: Filters): Client[] => {
  return clients.filter((client) => {
    let matches = true;

    if (filters.status && client.status !== filters.status) {
      matches = false;
    }

    return matches;
  });
};

const applyPagination = (
  clients: Client[],
  page: number,
  limit: number
): Client[] => {
  return clients.slice(page * limit, page * limit + limit);
};

const ClientsTable = () => {
  const [search, setSearch] = useState('');
  const searchHandle = (event) => {
    setSearch(event.target.value);
  };

  const fetchClients = async () => {
    let clients = [];
    if (search === '') {
      clients = await findAll();
    } else {
      clients = await findSearch(search);
    }
    setClients(clients);
  };
  const [clients, setClients] = useState<Client[]>([]);
  useEffect(() => {
    const fetch = async () => {
      let clients = [];
      if (search === '') {
        clients = await findAll();
      } else {
        clients = await findSearch(search);
      }
      setClients(clients);
    };
    fetch();
  }, [setClients, search]);

  const [open, setOpen] = React.useState(false);
  const handleOpen = () => setOpen(true);
  const handleClose = () => setOpen(false);

  const [selectedClients] = useState<string[]>([]);
  const [selectId, setSelectId] = useState<string>();

  const handleSelectedClientId = (id): void => {
    setSelectId(id);
  };
  const [page, setPage] = useState<number>(0);
  const [limit, setLimit] = useState<number>(5);
  const [filters /*setFilters*/] = useState<Filters>({
    status: null,
  });

  // const statusOptions = [
  //   {
  //     id: 'all',
  //     name: 'All',
  //   },
  //   {
  //     id: 'active',
  //     name: 'Ativo',
  //   },
  //   {
  //     id: 'inactive',
  //     name: 'Inativo',
  //   },
  // ];

  // const handleStatusChange = (e: ChangeEvent<HTMLInputElement>): void => {
  //   let value = null;

  //   if (e.target.value !== 'all') {
  //     value = e.target.value;
  //   }

  //   setFilters((prevFilters) => ({
  //     ...prevFilters,
  //     status: value,
  //   }));
  // };

  const handlePageChange = (event: any, newPage: number): void => {
    setPage(newPage);
  };

  const handleLimitChange = (event: ChangeEvent<HTMLInputElement>): void => {
    setLimit(parseInt(event.target.value));
  };

  const filteredClients = applyFilters(clients, filters);
  const paginatedClients = applyPagination(filteredClients, page, limit);
  const theme = useTheme();

  const handleDelete = async (id) => {
    const clientId = id;
    const client: Client = await remove(clientId);
    if (client.id === clientId) {
      fetchClients();
    } else {
      alert('Erro ao deletar o cliente!');
    }
  };

  return (
    <>
      <Grid container justifyContent="right">
        <Grid item mb={2} md={4}>
          <TextField
            fullWidth
            size="small"
            sx={{ mt: { xs: 2, md: 0 } }}
            label="Pesquise pelo nome, finalidade ou código do imóvel"
            onBlur={searchHandle}
          />
        </Grid>
        <Grid item ml={2}>
          <Button
            sx={{ mt: { xs: 2, md: 0 } }}
            variant="contained"
            startIcon={<SearchTwoToneIcon fontSize="small" />}
            onClick={fetchClients}
          >
            Pesquisar
          </Button>
        </Grid>
      </Grid>
      <Card>
        {/* {selectedBulkActions && (
          <Box flex={1} p={2}>
            <BulkActions />
          </Box>
        )}
        {!selectedBulkActions && (
          <CardHeader
            action={
              <Box width={150}>
                <FormControl fullWidth variant="outlined">
                  <InputLabel>Status</InputLabel>
                  <Select
                    value={filters.status || 'all'}
                    onChange={handleStatusChange}
                    label="Status"
                    autoWidth
                  >
                    {statusOptions.map((statusOption) => (
                      <MenuItem key={statusOption.id} value={statusOption.id}>
                        {statusOption.name}
                      </MenuItem>
                    ))}
                  </Select>
                </FormControl>
              </Box>
            }
          />
        )}
        <Divider /> */}
        <TableContainer>
          <Table>
            <TableHead>
              <TableRow>
                <TableCell>Nome</TableCell>
                <TableCell>Finalidade</TableCell>
                <TableCell>Código do imóvel</TableCell>
                <TableCell align="right">Ações</TableCell>
              </TableRow>
            </TableHead>
            <TableBody>
              {paginatedClients.map((client) => {
                const isCryptoOrderSelected = selectedClients.includes(
                  client.id
                );
                return (
                  <TableRow
                    hover
                    key={client.id}
                    selected={isCryptoOrderSelected}
                  >
                    <TableCell>
                      <Typography
                        variant="body1"
                        fontWeight="bold"
                        color="text.primary"
                        gutterBottom
                        noWrap
                      >
                        {(client.personValue === 'physical' &&
                          client.name_physicalPerson_locatario) ||
                          client.companyName_juridicalPerson_locatario}
                      </Typography>
                      <Typography variant="body2" color="text.secondary" noWrap>
                        {/* {format(client.updatedAt, 'MMMM dd yyyy')} */}
                      </Typography>
                    </TableCell>
                    <TableCell>
                      <Typography
                        variant="body1"
                        fontWeight="bold"
                        color="text.primary"
                        gutterBottom
                        noWrap
                      >
                        {client.goal}
                      </Typography>
                    </TableCell>
                    <TableCell>
                      <Typography
                        variant="body1"
                        fontWeight="bold"
                        color="text.primary"
                        gutterBottom
                        noWrap
                      >
                        {client.propertyCode}
                      </Typography>
                    </TableCell>
                    <TableCell align="right">
                      <Tooltip title="Exibir cadastro" arrow>
                        <IconButton
                          component={NavLink}
                          to={{ pathname: `view/${client.id}` }}
                          sx={{
                            '&:hover': {
                              background: theme.colors.primary.lighter,
                            },
                            color: theme.palette.primary.main,
                          }}
                          color="inherit"
                          size="small"
                        >
                          <ArticleTwoToneIcon />
                        </IconButton>
                      </Tooltip>

                      <Tooltip title="Editar cadastro" arrow>
                        <IconButton
                          component={NavLink}
                          to={{ pathname: `edit/${client.id}` }}
                          sx={{
                            '&:hover': {
                              background: theme.colors.primary.lighter,
                            },
                            color: theme.palette.primary.main,
                          }}
                          color="inherit"
                          size="small"
                        >
                          <EditTwoToneIcon fontSize="small" />
                        </IconButton>
                      </Tooltip>
                      <Tooltip title="Excluir cadastro" arrow>
                        <IconButton
                          sx={{
                            '&:hover': {
                              background: theme.colors.error.lighter,
                            },
                            color: theme.palette.error.main,
                          }}
                          color="inherit"
                          size="small"
                          onClick={() => {
                            handleSelectedClientId(client.id);
                            handleOpen();
                          }}
                        >
                          <DeleteTwoToneIcon fontSize="small" />
                        </IconButton>
                      </Tooltip>
                    </TableCell>
                  </TableRow>
                );
              })}
            </TableBody>
          </Table>
        </TableContainer>
        <Box p={2}>
          <TablePagination
            component="div"
            count={filteredClients.length}
            onPageChange={handlePageChange}
            onRowsPerPageChange={handleLimitChange}
            page={page}
            rowsPerPage={limit}
            rowsPerPageOptions={[5, 10, 25, 30]}
          />
        </Box>
      </Card>

      <Modal
        open={open}
        onClose={handleClose}
        aria-labelledby="modal-modal-title"
        aria-describedby="modal-modal-description"
      >
        <Box sx={style}>
          <Typography id="modal-modal-title" variant="h6" component="h2">
            Confirme a exclusão do contrato!
          </Typography>
          <Typography id="modal-modal-description" sx={{ mt: 2 }}>
            <Grid container>
              <Grid item xs={6} md={6}>
                <Button
                  sx={{ mt: { xs: 0, md: 0 } }}
                  variant="outlined"
                  startIcon={<KeyboardReturnTwoToneIcon fontSize="small" />}
                  onClick={handleClose}
                >
                  Retornar
                </Button>
              </Grid>
              <Grid item xs={6} md={6}>
                <Button
                  variant="outlined"
                  color="error"
                  startIcon={<DeleteTwoToneIcon />}
                  onClick={() => {
                    handleDelete(selectId);
                    handleClose();
                  }}
                >
                  Excluir
                </Button>
              </Grid>
            </Grid>
          </Typography>
        </Box>
      </Modal>
    </>
  );
};

ClientsTable.propTypes = {
  clients: PropTypes.array.isRequired,
};

ClientsTable.defaultProps = {
  clients: [],
};

export default ClientsTable;
