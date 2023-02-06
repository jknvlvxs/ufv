import { Container, Grid } from '@mui/material';
import { Helmet } from 'react-helmet-async';
import Footer from 'src/components/Footer';
import PageTitleWrapper from 'src/components/PageTitleWrapper';
import ClientsTable from './ClientsTable';
import PageHeader from './PageHeader';

function Clients() {
  return (
    <>
      <Helmet>
        <title>Clientes</title>
      </Helmet>
      <PageTitleWrapper>
        <PageHeader />
      </PageTitleWrapper>
      <Container maxWidth="lg">
        <Grid
          container
          direction="row"
          justifyContent="center"
          alignItems="stretch"
          spacing={3}
        >
          <Grid item xs={12}>
            <ClientsTable />
          </Grid>
        </Grid>
      </Container>
      <Footer />
    </>
  );
}

export default Clients;
