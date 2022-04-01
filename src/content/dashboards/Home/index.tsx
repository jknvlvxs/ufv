import { Helmet } from 'react-helmet-async';
import PageHeader from './PageHeader';
import PageTitleWrapper from 'src/components/PageTitleWrapper';
import { Grid, Container } from '@mui/material';
import Footer from 'src/components/Footer';

import Consultas from './Consultas';
import Wallets from './Wallets';
import AccountSecurity from './AccountSecurity';
import WatchList from './WatchList';
import ConsultaA from './ConsultaA';
import ConsultaC from './ConsultaC';
import ConsultaE from './ConsultaE';
import ConsultaF from './ConsultaF';
import ConsultaB from './ConsultaB';

function Home() {
  return (
    <>
      <Helmet>
        <title>Início</title>
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
            <Consultas />
          </Grid>
          <Grid item lg={4} xs={12}>
            <ConsultaA />
          </Grid>
          <Grid item lg={8} xs={12}>
            <ConsultaC />
          </Grid>
          <Grid item lg={4} xs={12}>
            <ConsultaE />
          </Grid>
          <Grid item lg={4} xs={12}>
            <ConsultaF />
          </Grid>
          <Grid item lg={4} xs={12}>
            <ConsultaB />
          </Grid>
          {/* <Grid item lg={8} xs={12}>
            <Wallets />
          </Grid> */}
          {/* <Grid item xs={12}>
            <WatchList />
          </Grid> */}
        </Grid>
      </Container>
      <Footer />
    </>
  );
}

export default Home;
