import { lazy, Suspense } from 'react';
import { PartialRouteObject } from 'react-router';
import { Navigate } from 'react-router-dom';
import SuspenseLoader from 'src/components/SuspenseLoader';
import BaseLayout from 'src/layouts/BaseLayout';
import SidebarLayout from 'src/layouts/SidebarLayout';

const Loader = (Component) => (props) =>
  (
    <Suspense fallback={<SuspenseLoader />}>
      <Component {...props} />
    </Suspense>
  );

// Dashboards

const Home = Loader(lazy(() => import('src/content/dashboards/Home')));

// Applications

const Clients = Loader(lazy(() => import('src/content/applications/Clients')));
const CreateClient = Loader(
  lazy(() => import('src/content/applications/Clients/create'))
);
const ViewClient = Loader(
  lazy(() => import('src/content/applications/Clients/view'))
);
const UpdateClient = Loader(
  lazy(() => import('src/content/applications/Clients/update'))
);

const Hotels = Loader(lazy(() => import('src/content/applications/Hotels')));
const CreateHotel = Loader(
  lazy(() => import('src/content/applications/Hotels/create'))
);

// Status

const Status404 = Loader(
  lazy(() => import('src/content/pages/Status/Status404'))
);
const Status500 = Loader(
  lazy(() => import('src/content/pages/Status/Status500'))
);
const StatusComingSoon = Loader(
  lazy(() => import('src/content/pages/Status/ComingSoon'))
);
const StatusMaintenance = Loader(
  lazy(() => import('src/content/pages/Status/Maintenance'))
);
const routes: PartialRouteObject[] = [
    {
      path: '',
      element: <BaseLayout />,
      children: [
        {
          path: '/',
          element: <Navigate to="/home" replace />,
        },
        {
          path: 'status',
          children: [
            {
              path: '/',
              element: <Navigate to="404" replace />,
            },
            {
              path: '404',
              element: <Status404 />,
            },
            {
              path: '500',
              element: <Status500 />,
            },
            {
              path: 'maintenance',
              element: <StatusMaintenance />,
            },
            {
              path: 'coming-soon',
              element: <StatusComingSoon />,
            },
          ],
        },
        {
          path: '*',
          element: <Status404 />,
        },
      ],
    },
    {
      path: 'home',
      element: <SidebarLayout />,
      children: [
        {
          path: '/',
          element: <Home />,
        },
      ],
    },
    {
      path: '',
      element: <SidebarLayout />,
      children: [
        {
          path: '/',
          element: <Navigate to="/" replace />,
        },
        {
          path: 'hotels',
          children: [
            {
              path: '/',
              element: <Hotels />,
            },
            {
              path: 'new',
              element: <CreateHotel />,
            },
            {
              path: 'view/:id',
              element: <ViewClient />,
            },
            {
              path: 'edit/:id',
              element: <UpdateClient />,
            },
          ],
        },
        {
          path: 'clients',
          children: [
            {
              path: '/',
              element: <Clients />,
            },
            {
              path: 'new',
              element: <CreateClient />,
            },
            {
              path: 'view/:id',
              element: <ViewClient />,
            },
            {
              path: 'edit/:id',
              element: <UpdateClient />,
            },
          ],
        },
      ],
    }
  ]

export default routes;
