import { Helmet } from 'react-helmet-async';
import PageHeader from './PageHeader';
import PageTitleWrapper from 'src/components/PageTitleWrapper';
import { Grid, Container } from '@mui/material';
import Footer from 'src/components/Footer';
import UpdateWrapper from './UpdateWrapper';

function UpdateUsers() {
  return (
    <>
      <Helmet children={<title children="Atualizar Usuário" />} />
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
            children={<Grid item xs={12} children={<UpdateWrapper />} />}
          />
        }
      />
      <Footer />
    </>
  );
}

export default UpdateUsers;
