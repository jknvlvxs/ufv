import { Container, Grid } from '@mui/material';
import { Helmet } from 'react-helmet-async';
import Footer from 'src/components/Footer';
import PageTitleWrapper from 'src/components/PageTitleWrapper';
import UsersTable from './UsersTable';
import PageHeader from './PageHeader';

function Users() {
  return (
    <>
      <Helmet children={<title children="Usuários" />} />
      <PageTitleWrapper children={<PageHeader />} />
      <Container
        maxWidth="lg"
        children={
          <Grid
            container
            direction="row"
            justifyContent="center"
            alignItems="stretch"
            spacing={3}
            children={<Grid item xs={12} children={<UsersTable />} />}
          />
        }
      />
      <Footer />
    </>
  );
}

export default Users;
