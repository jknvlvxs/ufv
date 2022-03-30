import { Grid, Typography } from "@mui/material";

function PageHeader() {
  const user = {
    name: "Catherine Pike",
  };

  return (
    <Grid container alignItems="center">
      <Grid item>
        <Typography variant="h3" component="h3" gutterBottom>
          Bem vindo(a), {user.name}!
        </Typography>
      </Grid>
    </Grid>
  );
}

export default PageHeader;
